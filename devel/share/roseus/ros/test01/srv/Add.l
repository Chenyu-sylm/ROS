;; Auto-generated. Do not edit!


(when (boundp 'test01::Add)
  (if (not (find-package "TEST01"))
    (make-package "TEST01"))
  (shadow 'Add (find-package "TEST01")))
(unless (find-package "TEST01::ADD")
  (make-package "TEST01::ADD"))
(unless (find-package "TEST01::ADDREQUEST")
  (make-package "TEST01::ADDREQUEST"))
(unless (find-package "TEST01::ADDRESPONSE")
  (make-package "TEST01::ADDRESPONSE"))

(in-package "ROS")





(defclass test01::AddRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod test01::AddRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass test01::AddResponse
  :super ros::object
  :slots (_sum ))

(defmethod test01::AddResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass test01::Add
  :super ros::object
  :slots ())

(setf (get test01::Add :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get test01::Add :datatype-) "test01/Add")
(setf (get test01::Add :request) test01::AddRequest)
(setf (get test01::Add :response) test01::AddResponse)

(defmethod test01::AddRequest
  (:response () (instance test01::AddResponse :init)))

(setf (get test01::AddRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get test01::AddRequest :datatype-) "test01/AddRequest")
(setf (get test01::AddRequest :definition-)
      "# 服务通信自定义消息格式
    #客户端
int32 num1
int32 num2
---
    #服务端
int32 sum
")

(setf (get test01::AddResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get test01::AddResponse :datatype-) "test01/AddResponse")
(setf (get test01::AddResponse :definition-)
      "# 服务通信自定义消息格式
    #客户端
int32 num1
int32 num2
---
    #服务端
int32 sum
")



(provide :test01/Add "4781436a0c2affec8025955a6041e481")


