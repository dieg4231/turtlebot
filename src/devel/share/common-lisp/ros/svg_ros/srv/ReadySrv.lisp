; Auto-generated. Do not edit!


(cl:in-package svg_ros-srv)


;//! \htmlinclude ReadySrv-request.msg.html

(cl:defclass <ReadySrv-request> (roslisp-msg-protocol:ros-message)
  ((ready
    :reader ready
    :initarg :ready
    :type cl:integer
    :initform 0))
)

(cl:defclass ReadySrv-request (<ReadySrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReadySrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReadySrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<ReadySrv-request> is deprecated: use svg_ros-srv:ReadySrv-request instead.")))

(cl:ensure-generic-function 'ready-val :lambda-list '(m))
(cl:defmethod ready-val ((m <ReadySrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:ready-val is deprecated.  Use svg_ros-srv:ready instead.")
  (ready m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReadySrv-request>) ostream)
  "Serializes a message object of type '<ReadySrv-request>"
  (cl:let* ((signed (cl:slot-value msg 'ready)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReadySrv-request>) istream)
  "Deserializes a message object of type '<ReadySrv-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ready) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReadySrv-request>)))
  "Returns string type for a service object of type '<ReadySrv-request>"
  "svg_ros/ReadySrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadySrv-request)))
  "Returns string type for a service object of type 'ReadySrv-request"
  "svg_ros/ReadySrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReadySrv-request>)))
  "Returns md5sum for a message object of type '<ReadySrv-request>"
  "481bf4557884a8ae5f3651bd90c8f18f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReadySrv-request)))
  "Returns md5sum for a message object of type 'ReadySrv-request"
  "481bf4557884a8ae5f3651bd90c8f18f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReadySrv-request>)))
  "Returns full string definition for message of type '<ReadySrv-request>"
  (cl:format cl:nil "int32 ready~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReadySrv-request)))
  "Returns full string definition for message of type 'ReadySrv-request"
  (cl:format cl:nil "int32 ready~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReadySrv-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReadySrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ReadySrv-request
    (cl:cons ':ready (ready msg))
))
;//! \htmlinclude ReadySrv-response.msg.html

(cl:defclass <ReadySrv-response> (roslisp-msg-protocol:ros-message)
  ((answer
    :reader answer
    :initarg :answer
    :type cl:integer
    :initform 0))
)

(cl:defclass ReadySrv-response (<ReadySrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ReadySrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ReadySrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<ReadySrv-response> is deprecated: use svg_ros-srv:ReadySrv-response instead.")))

(cl:ensure-generic-function 'answer-val :lambda-list '(m))
(cl:defmethod answer-val ((m <ReadySrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:answer-val is deprecated.  Use svg_ros-srv:answer instead.")
  (answer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ReadySrv-response>) ostream)
  "Serializes a message object of type '<ReadySrv-response>"
  (cl:let* ((signed (cl:slot-value msg 'answer)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ReadySrv-response>) istream)
  "Deserializes a message object of type '<ReadySrv-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'answer) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ReadySrv-response>)))
  "Returns string type for a service object of type '<ReadySrv-response>"
  "svg_ros/ReadySrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadySrv-response)))
  "Returns string type for a service object of type 'ReadySrv-response"
  "svg_ros/ReadySrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ReadySrv-response>)))
  "Returns md5sum for a message object of type '<ReadySrv-response>"
  "481bf4557884a8ae5f3651bd90c8f18f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ReadySrv-response)))
  "Returns md5sum for a message object of type 'ReadySrv-response"
  "481bf4557884a8ae5f3651bd90c8f18f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ReadySrv-response>)))
  "Returns full string definition for message of type '<ReadySrv-response>"
  (cl:format cl:nil "int32 answer~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ReadySrv-response)))
  "Returns full string definition for message of type 'ReadySrv-response"
  (cl:format cl:nil "int32 answer~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ReadySrv-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ReadySrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ReadySrv-response
    (cl:cons ':answer (answer msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ReadySrv)))
  'ReadySrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ReadySrv)))
  'ReadySrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ReadySrv)))
  "Returns string type for a service object of type '<ReadySrv>"
  "svg_ros/ReadySrv")