#!/usr/bin/env python3

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
import cv2
from ultralytics import YOLO

class YOLOv8Detector:
    def __init__(self, model_path):
        # YOLOv8 모델 로드
        self.model = YOLO(model_path, task='detect')
        rospy.loginfo("YOLOv8 모델이 성공적으로 로드되었습니다.")
        
        self.bridge = CvBridge()
        self.confidence_threshold = 0.3
        
        # ROS 노드 초기화
        rospy.init_node('ledbar_detector_node', anonymous=True)
        self.image_sub = rospy.Subscriber('/camera/color/image_raw', Image, self.image_callback)
        self.detection_image_pub = rospy.Publisher('/yolov8/detection_image', Image, queue_size=10)

    def preprocess_image(self, cv_image):
        """이미지를 모델 입력 크기로 조정"""
        original_height, original_width = cv_image.shape[:2]
        resized_image = cv2.resize(cv_image, (640, 640))  # 640x640 크기로 조정
        return resized_image, original_width, original_height

    def draw_boxes(self, cv_image, results, original_width, original_height):
        """탐지 결과를 이미지에 그리기"""
        for result in results:
            for box in result.boxes:
                x1, y1, x2, y2 = map(int, box.xyxy[0])
                conf = box.conf[0]
                cls = box.cls[0]
                
                if conf >= self.confidence_threshold:
                    # 원본 이미지 크기에 맞게 경계 상자 비율 조정
                    pt1 = (int(x1 * original_width / 640), int(y1 * original_height / 640))
                    pt2 = (int(x2 * original_width / 640), int(y2 * original_height / 640))

                    # 경계 상자 좌표 출력
                    rospy.loginfo(f'경계 상자 좌표: pt1={pt1}, pt2={pt2}')
                    
                    color = (0, 255, 0)  # BGR 형식의 초록색
                    thickness = 2
                    cv2.rectangle(cv_image, pt1, pt2, color, thickness)
                    label = f'{self.model.names[int(cls)]} {conf:.2f}'
                    cv2.putText(cv_image, label, (pt1[0], pt1[1]-10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)
        return cv_image

    def image_callback(self, msg):
        """ROS 이미지 콜백 함수"""
        try:
            # ROS 이미지 메시지를 OpenCV 이미지로 변환
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            rospy.loginfo("이미지를 수신하고 변환했습니다.")
            
            # 이미지 전처리 및 객체 감지 수행
            resized_image, original_width, original_height = self.preprocess_image(cv_image)
            results = self.model(resized_image)
            rospy.loginfo("객체 탐지를 수행했습니다.")
            
            # 탐지 결과 처리 및 이미지 후처리
            cv_image = self.draw_boxes(cv_image, results, original_width, original_height)
            rospy.loginfo("이미지에 경계 상자 및 레이블을 그렸습니다.")
            
            # OpenCV 이미지를 ROS 이미지 메시지로 변환
            ros_image = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
            rospy.loginfo("이미지를 ROS 이미지 메시지로 변환했습니다.")
            
            # 이미지 퍼블리시
            self.detection_image_pub.publish(ros_image)
            rospy.loginfo("이미지를 퍼블리시했습니다.")
            
        except CvBridgeError as e:
            rospy.logerr(f'CvBridge Error: {e}')
        except AttributeError as e:
            rospy.logerr(f'Attribute Error: {e}')
        except Exception as e:
            rospy.logerr(f'Error: {e}')

def main():
    # 모델 경로 설정
    model_path = "/home/ubuntu/catkin_ws/src/Redbot02/redbot02_camera_detection/best_ncnn_model"
    
    # YOLOv8 객체 감지 인스턴스 생성
    detector = YOLOv8Detector(model_path)
    
    rospy.loginfo("YOLOv8 노드가 실행 중입니다...")
    rospy.spin()

if __name__ == '__main__':
    main()
