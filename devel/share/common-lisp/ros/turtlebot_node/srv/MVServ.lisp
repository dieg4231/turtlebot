; Auto-generated. Do not edit!


(cl:in-package turtlebot_node-srv)


;//! \htmlinclude MVServ-request.msg.html

(cl:defclass <MVServ-request> (roslisp-msg-protocol:ros-message)
  ((param
    :reader param
    :initarg :param
    :type cl:string
    :initform "")
   (coord_x
    :reader coord_x
    :initarg :coord_x
    :type cl:float
    :initform 0.0)
   (coord_y
    :reader coord_y
    :initarg :coord_y
    :type cl:float
    :initform 0.0)
   (coord_ang
    :reader coord_ang
    :initarg :coord_ang
    :type cl:float
    :initform 0.0))
)

(cl:defclass MVServ-request (<MVServ-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MVServ-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MVServ-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_node-srv:<MVServ-request> is deprecated: use turtlebot_node-srv:MVServ-request instead.")))

(cl:ensure-generic-function 'param-val :lambda-list '(m))
(cl:defmethod param-val ((m <MVServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_node-srv:param-val is deprecated.  Use turtlebot_node-srv:param instead.")
  (param m))

(cl:ensure-generic-function 'coord_x-val :lambda-list '(m))
(cl:defmethod coord_x-val ((m <MVServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_node-srv:coord_x-val is deprecated.  Use turtlebot_node-srv:coord_x instead.")
  (coord_x m))

(cl:ensure-generic-function 'coord_y-val :lambda-list '(m))
(cl:defmethod coord_y-val ((m <MVServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_node-srv:coord_y-val is deprecated.  Use turtlebot_node-srv:coord_y instead.")
  (coord_y m))

(cl:ensure-generic-function 'coord_ang-val :lambda-list '(m))
(cl:defmethod coord_ang-val ((m <MVServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_node-srv:coord_ang-val is deprecated.  Use turtlebot_node-srv:coord_ang instead.")
  (coord_ang m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MVServ-request>) ostream)
  "Serializes a message object of type '<MVServ-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'param))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'param))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'coord_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'coord_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'coord_ang))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MVServ-request>) istream)
  "Deserializes a message object of type '<MVServ-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'param) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'param) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'coord_x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'coord_y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'coord_ang) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MVServ-request>)))
  "Returns string type for a service object of type '<MVServ-request>"
  "turtlebot_node/MVServRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MVServ-request)))
  "Returns string type for a service object of type 'MVServ-request"
  "turtlebot_node/MVServRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MVServ-request>)))
  "Returns md5sum for a message object of type '<MVServ-request>"
  "a5027d7394e6db0c454d58003c11ba06")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MVServ-request)))
  "Returns md5sum for a message object of type 'MVServ-request"
  "a5027d7394e6db0c454d58003c11ba06")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MVServ-request>)))
  "Returns full string definition for message of type '<MVServ-request>"
  (cl:format cl:nil "string param~%float32 coord_x~%float32 coord_y~%float32 coord_ang~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MVServ-request)))
  "Returns full string definition for message of type 'MVServ-request"
  (cl:format cl:nil "string param~%float32 coord_x~%float32 coord_y~%float32 coord_ang~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MVServ-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'param))
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MVServ-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MVServ-request
    (cl:cons ':param (param msg))
    (cl:cons ':coord_x (coord_x msg))
    (cl:cons ':coord_y (coord_y msg))
    (cl:cons ':coord_ang (coord_ang msg))
))
;//! \htmlinclude MVServ-response.msg.html

(cl:defclass <MVServ-response> (roslisp-msg-protocol:ros-message)
  ((answer
    :reader answer
    :initarg :answer
    :type cl:string
    :initform ""))
)

(cl:defclass MVServ-response (<MVServ-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MVServ-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MVServ-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_node-srv:<MVServ-response> is deprecated: use turtlebot_node-srv:MVServ-response instead.")))

(cl:ensure-generic-function 'answer-val :lambda-list '(m))
(cl:defmethod answer-val ((m <MVServ-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_node-srv:answer-val is deprecated.  Use turtlebot_node-srv:answer instead.")
  (answer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MVServ-response>) ostream)
  "Serializes a message object of type '<MVServ-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'answer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'answer))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MVServ-response>) istream)
  "Deserializes a message object of type '<MVServ-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'answer) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'answer) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MVServ-response>)))
  "Returns string type for a service object of type '<MVServ-response>"
  "turtlebot_node/MVServResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MVServ-response)))
  "Returns string type for a service object of type 'MVServ-response"
  "turtlebot_node/MVServResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MVServ-response>)))
  "Returns md5sum for a message object of type '<MVServ-response>"
  "a5027d7394e6db0c454d58003c11ba06")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MVServ-response)))
  "Returns md5sum for a message object of type 'MVServ-response"
  "a5027d7394e6db0c454d58003c11ba06")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MVServ-response>)))
  "Returns full string definition for message of type '<MVServ-response>"
  (cl:format cl:nil "string answer~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MVServ-response)))
  "Returns full string definition for message of type 'MVServ-response"
  (cl:format cl:nil "string answer~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MVServ-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'answer))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MVServ-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MVServ-response
    (cl:cons ':answer (answer msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MVServ)))
  'MVServ-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MVServ)))
  'MVServ-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MVServ)))
  "Returns string type for a service object of type '<MVServ>"
  "turtlebot_node/MVServ")