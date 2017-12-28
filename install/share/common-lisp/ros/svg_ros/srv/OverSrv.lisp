; Auto-generated. Do not edit!


(cl:in-package svg_ros-srv)


;//! \htmlinclude OverSrv-request.msg.html

(cl:defclass <OverSrv-request> (roslisp-msg-protocol:ros-message)
  ((over_flg
    :reader over_flg
    :initarg :over_flg
    :type cl:integer
    :initform 0))
)

(cl:defclass OverSrv-request (<OverSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <OverSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'OverSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<OverSrv-request> is deprecated: use svg_ros-srv:OverSrv-request instead.")))

(cl:ensure-generic-function 'over_flg-val :lambda-list '(m))
(cl:defmethod over_flg-val ((m <OverSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:over_flg-val is deprecated.  Use svg_ros-srv:over_flg instead.")
  (over_flg m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <OverSrv-request>) ostream)
  "Serializes a message object of type '<OverSrv-request>"
  (cl:let* ((signed (cl:slot-value msg 'over_flg)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <OverSrv-request>) istream)
  "Deserializes a message object of type '<OverSrv-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'over_flg) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<OverSrv-request>)))
  "Returns string type for a service object of type '<OverSrv-request>"
  "svg_ros/OverSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OverSrv-request)))
  "Returns string type for a service object of type 'OverSrv-request"
  "svg_ros/OverSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<OverSrv-request>)))
  "Returns md5sum for a message object of type '<OverSrv-request>"
  "ed5c22717a93863499734f374ca8e9a3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'OverSrv-request)))
  "Returns md5sum for a message object of type 'OverSrv-request"
  "ed5c22717a93863499734f374ca8e9a3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<OverSrv-request>)))
  "Returns full string definition for message of type '<OverSrv-request>"
  (cl:format cl:nil "int32 over_flg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'OverSrv-request)))
  "Returns full string definition for message of type 'OverSrv-request"
  (cl:format cl:nil "int32 over_flg~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <OverSrv-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <OverSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'OverSrv-request
    (cl:cons ':over_flg (over_flg msg))
))
;//! \htmlinclude OverSrv-response.msg.html

(cl:defclass <OverSrv-response> (roslisp-msg-protocol:ros-message)
  ((answer
    :reader answer
    :initarg :answer
    :type cl:integer
    :initform 0))
)

(cl:defclass OverSrv-response (<OverSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <OverSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'OverSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<OverSrv-response> is deprecated: use svg_ros-srv:OverSrv-response instead.")))

(cl:ensure-generic-function 'answer-val :lambda-list '(m))
(cl:defmethod answer-val ((m <OverSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:answer-val is deprecated.  Use svg_ros-srv:answer instead.")
  (answer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <OverSrv-response>) ostream)
  "Serializes a message object of type '<OverSrv-response>"
  (cl:let* ((signed (cl:slot-value msg 'answer)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <OverSrv-response>) istream)
  "Deserializes a message object of type '<OverSrv-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'answer) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<OverSrv-response>)))
  "Returns string type for a service object of type '<OverSrv-response>"
  "svg_ros/OverSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OverSrv-response)))
  "Returns string type for a service object of type 'OverSrv-response"
  "svg_ros/OverSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<OverSrv-response>)))
  "Returns md5sum for a message object of type '<OverSrv-response>"
  "ed5c22717a93863499734f374ca8e9a3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'OverSrv-response)))
  "Returns md5sum for a message object of type 'OverSrv-response"
  "ed5c22717a93863499734f374ca8e9a3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<OverSrv-response>)))
  "Returns full string definition for message of type '<OverSrv-response>"
  (cl:format cl:nil "int32 answer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'OverSrv-response)))
  "Returns full string definition for message of type 'OverSrv-response"
  (cl:format cl:nil "int32 answer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <OverSrv-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <OverSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'OverSrv-response
    (cl:cons ':answer (answer msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'OverSrv)))
  'OverSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'OverSrv)))
  'OverSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'OverSrv)))
  "Returns string type for a service object of type '<OverSrv>"
  "svg_ros/OverSrv")