#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2
import numpy as np

class LedColorDetector:
    def __init__(self):
        self.bridge = CvBridge()
        self.image_sub = rospy.Subscriber("/usb_cam/image_raw", Image, self.image_callback)
        rospy.loginfo("LED Color Detector Initialized")

    def image_callback(self, data):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
        except CvBridgeError as e:
            rospy.logerr("CvBridge Error: {0}".format(e))
            return

        # 이미지에서 LED 색깔 인식
        self.detect_led_color(cv_image)

    def detect_led_color(self, image):
        # 이미지 전처리 (필요에 따라 조정)
        blurred = cv2.GaussianBlur(image, (15, 15), 0)
        hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

        # 상단 및 하단 LED의 색깔 인식 (예: 빨강 및 파랑)
        upper_led_color = self.get_led_color(hsv, position='upper')
        lower_led_color = self.get_led_color(hsv, position='lower')

        rospy.loginfo("Upper LED Color: %s", upper_led_color)
        rospy.loginfo("Lower LED Color: %s", lower_led_color)
        rospy.loginfo("---------------")

    def get_led_color(self, hsv_image, position):
        # LED의 위치에 따라 ROI 설정
        height, width = hsv_image.shape[:2]
        if position == 'upper':
            roi = hsv_image[:height//2, :]
        else:
            roi = hsv_image[height//2:, :]

        # 색깔 범위 정의 (예시: 빨강 및 파랑)
        colors_ranges = {
            'red': ((0, 100, 100), (10, 255, 255)),
            'blue': ((110, 100, 100), (130, 255, 255)),
            'yellow': ((20, 100, 100), (30, 255, 255)),
            'green': ((40, 40, 40), (80, 255, 255))
            # 필요에 따라 더 많은 색상 추가
        }

        # 색깔 검출
        for color, (lower, upper) in colors_ranges.items():
            mask = cv2.inRange(roi, lower, upper)
            if cv2.countNonZero(mask) > 0:
                return color

        return 'unknown'

if __name__ == '__main__':
    rospy.init_node('led_color_detector', anonymous=True)
    lcd = LedColorDetector()
    try:
        rospy.spin()
    except KeyboardInterrupt:
        rospy.loginfo("Shutting down LED Color Detector")
    cv2.destroyAllWindows()
