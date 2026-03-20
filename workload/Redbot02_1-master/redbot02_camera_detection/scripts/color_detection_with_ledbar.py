#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2
import numpy as np

class LedColorDetector:
    def __init__(self):
        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber("/camera/color/image_raw", Image, self.image_callback)
        self.image_pub = rospy.Publisher("/camera/color/image_with_bounding_box", Image, queue_size=1)
        rospy.loginfo("LED Color Detector Initialized")

    def image_callback(self, data):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            rospy.logerr("CvBridge Error: {0}".format(e))
            return

        # 이미지에서 LED 색깔 인식
        cv_image = self.detect_led_color(cv_image)

        # 결과 이미지를 퍼블리시
        try:
            image_message = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
            self.image_pub.publish(image_message)
        except CvBridgeError as e:
            rospy.logerr("CvBridge Error: {0}".format(e))

    def detect_led_color(self, image):
        # 이미지 전처리
        blurred = cv2.GaussianBlur(image, (15, 15), 0)
        hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

        # 밝은 영역(LED 바) 검출
        bright_mask = cv2.inRange(hsv, (0, 0, 150), (180, 255, 255))  # 조정 필요
        bright_mask = cv2.erode(bright_mask, None, iterations=2)
        bright_mask = cv2.dilate(bright_mask, None, iterations=2)

        # 윤곽선 검출
        contours, _ = cv2.findContours(bright_mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        if contours:
            # 가장 큰 윤곽선을 LED 바로 가정
            for contour in contours:
                x, y, w, h = cv2.boundingRect(contour)
                aspect_ratio = h / float(w)

                # 세로/가로 비율이 약 15인 경우에만 처리
                if 5 <= aspect_ratio <= 25:
                    # LED 바 영역을 두 부분으로 나누기
                    upper_roi = hsv[y:y+h//2, x:x+w]
                    lower_roi = hsv[y+h//2:y+h, x:x+w]

                    upper_led_color = self.get_led_color(upper_roi)
                    lower_led_color = self.get_led_color(lower_roi)

                    rospy.loginfo("Upper LED Color: %s", upper_led_color)
                    rospy.loginfo("Lower LED Color: %s", lower_led_color)

                    # 바운딩 박스 그리기
                    cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2)
                    cv2.putText(image, "Upper: {}".format(upper_led_color), (x, y-10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                    cv2.putText(image, "Lower: {}".format(lower_led_color), (x, y+h+20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
                    break
        else:
            rospy.loginfo("No LED bar detected")

        return image

    def get_led_color(self, roi):
        # 더 세부적인 색깔 범위 정의
        colors_ranges = {
            'red': [
                ((0, 0, 40), (10, 255, 255)),    # 빨강 1
                ((160, 0, 40), (180, 255, 255))  # 빨강 2
            ],
            'blue': [
                ((100, 150, 0), (140, 255, 255))   # 파랑
            ],
            'yellow': [
                ((20, 100, 100), (40, 255, 255))    # 노랑
            ],
            'green': [
                ((35, 50, 50), (85, 255, 255))    # 초록
            ]
            # 필요에 따라 더 많은 색상 추가
        }

        max_color = 'unknown'
        max_area = 0

        # 색깔 검출
        for color, ranges in colors_ranges.items():
            for lower, upper in ranges:
                lower_np = np.array(lower)
                upper_np = np.array(upper)
                mask = cv2.inRange(roi, lower_np, upper_np)
                area = cv2.countNonZero(mask)

                if area > max_area:
                    max_area = area
                    max_color = color

        return max_color

if __name__ == '__main__':
    rospy.init_node('led_color_detector', anonymous=True)
    lcd = LedColorDetector()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        rospy.loginfo("Shutting down LED Color Detector")
    cv2.destroyAllWindows()
