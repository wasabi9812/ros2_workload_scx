import torch
from ultralytics import YOLO
import tensorflow as tf
import onnx
import tf2onnx

# YOLOv8 모델 로드
model_path = "/home/ubuntu/catkin_ws/src/yolov8/best.pt"
model = YOLO(model_path)

# 모델을 ONNX 형식으로 변환
onnx_path = "/home/ubuntu/catkin_ws/src/yolov8/best.onnx"
model.export(format='onnx', save_dir="/home/ubuntu/catkin_ws/src/yolov8")

# ONNX 모델을 TensorFlow 모델로 변환
onnx_model = onnx.load(onnx_path)

# ONNX 모델을 TensorFlow 모델로 변환
# 1. ONNX 모델을 TensorFlow로 변환
# 2. 변환된 모델을 SavedModel 포맷으로 저장
# 3. TensorFlow 모델을 TensorFlow Lite 모델로 변환

import tf2onnx
import tensorflow as tf

# Convert ONNX model to TensorFlow model
tf_rep = tf2onnx.tfonnx.process_tf_graph(tf.Graph().as_default(), input_names=["input:0"], 
                                           output_names=["output:0"], 
                                           model_path=onnx_path)

# Save TensorFlow model
output_path = "/home/ubuntu/catkin_ws/src/Redbot02/redbot02_camera_detection/tensorflow_model/model"
with tf.Graph().as_default() as tf_graph:
    tf.import_graph_def(tf_rep.graph_def, name="")
    with tf.compat.v1.Session(graph=tf_graph) as sess:
        tf.saved_model.simple_save(sess,
                                   output_path,
                                   inputs={"input:0": tf_graph.get_tensor_by_name("input:0")},
                                   outputs={"output:0": tf_graph.get_tensor_by_name("output:0")})

# TensorFlow 모델을 TensorFlow Lite 모델로 변환
converter = tf.lite.TFLiteConverter.from_saved_model(output_path)
tflite_model = converter.convert()

# TensorFlow Lite 모델 저장
tflite_model_path = "/home/ubuntu/catkin_ws/src/Redbot02/redbot02_camera_detection/tensorflow_model/model.tflite"
with open(tflite_model_path, "wb") as f:
    f.write(tflite_model)

print(f"TensorFlow Lite 모델이 {tflite_model_path}에 저장되었습니다.")
