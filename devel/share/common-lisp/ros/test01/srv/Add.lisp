; Auto-generated. Do not edit!


(cl:in-package test01-srv)


;//! \htmlinclude Add-request.msg.html

(cl:defclass <Add-request> (roslisp-msg-protocol:ros-message)
  ((num1
    :reader num1
    :initarg :num1
    :type cl:integer
    :initform 0)
   (num2
    :reader num2
    :initarg :num2
    :type cl:integer
    :initform 0))
)

(cl:defclass Add-request (<Add-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Add-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Add-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test01-srv:<Add-request> is deprecated: use test01-srv:Add-request instead.")))

(cl:ensure-generic-function 'num1-val :lambda-list '(m))
(cl:defmethod num1-val ((m <Add-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test01-srv:num1-val is deprecated.  Use test01-srv:num1 instead.")
  (num1 m))

(cl:ensure-generic-function 'num2-val :lambda-list '(m))
(cl:defmethod num2-val ((m <Add-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test01-srv:num2-val is deprecated.  Use test01-srv:num2 instead.")
  (num2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Add-request>) ostream)
  "Serializes a message object of type '<Add-request>"
  (cl:let* ((signed (cl:slot-value msg 'num1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'num2)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Add-request>) istream)
  "Deserializes a message object of type '<Add-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num1) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num2) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Add-request>)))
  "Returns string type for a service object of type '<Add-request>"
  "test01/AddRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Add-request)))
  "Returns string type for a service object of type 'Add-request"
  "test01/AddRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Add-request>)))
  "Returns md5sum for a message object of type '<Add-request>"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Add-request)))
  "Returns md5sum for a message object of type 'Add-request"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Add-request>)))
  "Returns full string definition for message of type '<Add-request>"
  (cl:format cl:nil "# 服务通信自定义消息格式~%    #客户端~%int32 num1~%int32 num2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Add-request)))
  "Returns full string definition for message of type 'Add-request"
  (cl:format cl:nil "# 服务通信自定义消息格式~%    #客户端~%int32 num1~%int32 num2~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Add-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Add-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Add-request
    (cl:cons ':num1 (num1 msg))
    (cl:cons ':num2 (num2 msg))
))
;//! \htmlinclude Add-response.msg.html

(cl:defclass <Add-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass Add-response (<Add-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Add-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Add-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test01-srv:<Add-response> is deprecated: use test01-srv:Add-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <Add-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test01-srv:sum-val is deprecated.  Use test01-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Add-response>) ostream)
  "Serializes a message object of type '<Add-response>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Add-response>) istream)
  "Deserializes a message object of type '<Add-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Add-response>)))
  "Returns string type for a service object of type '<Add-response>"
  "test01/AddResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Add-response)))
  "Returns string type for a service object of type 'Add-response"
  "test01/AddResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Add-response>)))
  "Returns md5sum for a message object of type '<Add-response>"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Add-response)))
  "Returns md5sum for a message object of type 'Add-response"
  "4781436a0c2affec8025955a6041e481")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Add-response>)))
  "Returns full string definition for message of type '<Add-response>"
  (cl:format cl:nil "    #服务端~%int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Add-response)))
  "Returns full string definition for message of type 'Add-response"
  (cl:format cl:nil "    #服务端~%int32 sum~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Add-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Add-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Add-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Add)))
  'Add-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Add)))
  'Add-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Add)))
  "Returns string type for a service object of type '<Add>"
  "test01/Add")