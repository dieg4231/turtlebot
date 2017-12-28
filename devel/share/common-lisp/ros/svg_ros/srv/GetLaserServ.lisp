; Auto-generated. Do not edit!


(cl:in-package svg_ros-srv)


;//! \htmlinclude GetLaserServ-request.msg.html

(cl:defclass <GetLaserServ-request> (roslisp-msg-protocol:ros-message)
  ((param
    :reader param
    :initarg :param
    :type cl:string
    :initform "")
   (num_sensors
    :reader num_sensors
    :initarg :num_sensors
    :type cl:integer
    :initform 0)
   (range
    :reader range
    :initarg :range
    :type cl:float
    :initform 0.0)
   (init_angle
    :reader init_angle
    :initarg :init_angle
    :type cl:float
    :initform 0.0))
)

(cl:defclass GetLaserServ-request (<GetLaserServ-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetLaserServ-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetLaserServ-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<GetLaserServ-request> is deprecated: use svg_ros-srv:GetLaserServ-request instead.")))

(cl:ensure-generic-function 'param-val :lambda-list '(m))
(cl:defmethod param-val ((m <GetLaserServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:param-val is deprecated.  Use svg_ros-srv:param instead.")
  (param m))

(cl:ensure-generic-function 'num_sensors-val :lambda-list '(m))
(cl:defmethod num_sensors-val ((m <GetLaserServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:num_sensors-val is deprecated.  Use svg_ros-srv:num_sensors instead.")
  (num_sensors m))

(cl:ensure-generic-function 'range-val :lambda-list '(m))
(cl:defmethod range-val ((m <GetLaserServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:range-val is deprecated.  Use svg_ros-srv:range instead.")
  (range m))

(cl:ensure-generic-function 'init_angle-val :lambda-list '(m))
(cl:defmethod init_angle-val ((m <GetLaserServ-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:init_angle-val is deprecated.  Use svg_ros-srv:init_angle instead.")
  (init_angle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetLaserServ-request>) ostream)
  "Serializes a message object of type '<GetLaserServ-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'param))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'param))
  (cl:let* ((signed (cl:slot-value msg 'num_sensors)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'range))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'init_angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetLaserServ-request>) istream)
  "Deserializes a message object of type '<GetLaserServ-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'param) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'param) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num_sensors) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'range) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'init_angle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetLaserServ-request>)))
  "Returns string type for a service object of type '<GetLaserServ-request>"
  "svg_ros/GetLaserServRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetLaserServ-request)))
  "Returns string type for a service object of type 'GetLaserServ-request"
  "svg_ros/GetLaserServRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetLaserServ-request>)))
  "Returns md5sum for a message object of type '<GetLaserServ-request>"
  "51e72a4807785eaabb7cee7d2a968e03")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetLaserServ-request)))
  "Returns md5sum for a message object of type 'GetLaserServ-request"
  "51e72a4807785eaabb7cee7d2a968e03")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetLaserServ-request>)))
  "Returns full string definition for message of type '<GetLaserServ-request>"
  (cl:format cl:nil "string param~%int32 num_sensors~%float32 range~%float32 init_angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetLaserServ-request)))
  "Returns full string definition for message of type 'GetLaserServ-request"
  (cl:format cl:nil "string param~%int32 num_sensors~%float32 range~%float32 init_angle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetLaserServ-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'param))
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetLaserServ-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetLaserServ-request
    (cl:cons ':param (param msg))
    (cl:cons ':num_sensors (num_sensors msg))
    (cl:cons ':range (range msg))
    (cl:cons ':init_angle (init_angle msg))
))
;//! \htmlinclude GetLaserServ-response.msg.html

(cl:defclass <GetLaserServ-response> (roslisp-msg-protocol:ros-message)
  ((answer
    :reader answer
    :initarg :answer
    :type cl:string
    :initform "")
   (sensors
    :reader sensors
    :initarg :sensors
    :type (cl:vector cl:float)
   :initform (cl:make-array 700 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass GetLaserServ-response (<GetLaserServ-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetLaserServ-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetLaserServ-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<GetLaserServ-response> is deprecated: use svg_ros-srv:GetLaserServ-response instead.")))

(cl:ensure-generic-function 'answer-val :lambda-list '(m))
(cl:defmethod answer-val ((m <GetLaserServ-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:answer-val is deprecated.  Use svg_ros-srv:answer instead.")
  (answer m))

(cl:ensure-generic-function 'sensors-val :lambda-list '(m))
(cl:defmethod sensors-val ((m <GetLaserServ-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:sensors-val is deprecated.  Use svg_ros-srv:sensors instead.")
  (sensors m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetLaserServ-response>) ostream)
  "Serializes a message object of type '<GetLaserServ-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'answer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'answer))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'sensors))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetLaserServ-response>) istream)
  "Deserializes a message object of type '<GetLaserServ-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'answer) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'answer) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:setf (cl:slot-value msg 'sensors) (cl:make-array 700))
  (cl:let ((vals (cl:slot-value msg 'sensors)))
    (cl:dotimes (i 700)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetLaserServ-response>)))
  "Returns string type for a service object of type '<GetLaserServ-response>"
  "svg_ros/GetLaserServResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetLaserServ-response)))
  "Returns string type for a service object of type 'GetLaserServ-response"
  "svg_ros/GetLaserServResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetLaserServ-response>)))
  "Returns md5sum for a message object of type '<GetLaserServ-response>"
  "51e72a4807785eaabb7cee7d2a968e03")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetLaserServ-response)))
  "Returns md5sum for a message object of type 'GetLaserServ-response"
  "51e72a4807785eaabb7cee7d2a968e03")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetLaserServ-response>)))
  "Returns full string definition for message of type '<GetLaserServ-response>"
  (cl:format cl:nil "string answer~%float32[700] sensors~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetLaserServ-response)))
  "Returns full string definition for message of type 'GetLaserServ-response"
  (cl:format cl:nil "string answer~%float32[700] sensors~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetLaserServ-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'answer))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'sensors) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetLaserServ-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetLaserServ-response
    (cl:cons ':answer (answer msg))
    (cl:cons ':sensors (sensors msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetLaserServ)))
  'GetLaserServ-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetLaserServ)))
  'GetLaserServ-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetLaserServ)))
  "Returns string type for a service object of type '<GetLaserServ>"
  "svg_ros/GetLaserServ")