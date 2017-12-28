; Auto-generated. Do not edit!


(cl:in-package svg_ros-srv)


;//! \htmlinclude MVPlannerSrv-request.msg.html

(cl:defclass <MVPlannerSrv-request> (roslisp-msg-protocol:ros-message)
  ((answer
    :reader answer
    :initarg :answer
    :type cl:string
    :initform ""))
)

(cl:defclass MVPlannerSrv-request (<MVPlannerSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MVPlannerSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MVPlannerSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<MVPlannerSrv-request> is deprecated: use svg_ros-srv:MVPlannerSrv-request instead.")))

(cl:ensure-generic-function 'answer-val :lambda-list '(m))
(cl:defmethod answer-val ((m <MVPlannerSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:answer-val is deprecated.  Use svg_ros-srv:answer instead.")
  (answer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MVPlannerSrv-request>) ostream)
  "Serializes a message object of type '<MVPlannerSrv-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'answer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'answer))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MVPlannerSrv-request>) istream)
  "Deserializes a message object of type '<MVPlannerSrv-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MVPlannerSrv-request>)))
  "Returns string type for a service object of type '<MVPlannerSrv-request>"
  "svg_ros/MVPlannerSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MVPlannerSrv-request)))
  "Returns string type for a service object of type 'MVPlannerSrv-request"
  "svg_ros/MVPlannerSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MVPlannerSrv-request>)))
  "Returns md5sum for a message object of type '<MVPlannerSrv-request>"
  "5f074d799916e31d387cc1b1bc10d8d7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MVPlannerSrv-request)))
  "Returns md5sum for a message object of type 'MVPlannerSrv-request"
  "5f074d799916e31d387cc1b1bc10d8d7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MVPlannerSrv-request>)))
  "Returns full string definition for message of type '<MVPlannerSrv-request>"
  (cl:format cl:nil "string answer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MVPlannerSrv-request)))
  "Returns full string definition for message of type 'MVPlannerSrv-request"
  (cl:format cl:nil "string answer~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MVPlannerSrv-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'answer))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MVPlannerSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MVPlannerSrv-request
    (cl:cons ':answer (answer msg))
))
;//! \htmlinclude MVPlannerSrv-response.msg.html

(cl:defclass <MVPlannerSrv-response> (roslisp-msg-protocol:ros-message)
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
    :initform 0.0)
   (flgGUI
    :reader flgGUI
    :initarg :flgGUI
    :type cl:integer
    :initform 0))
)

(cl:defclass MVPlannerSrv-response (<MVPlannerSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MVPlannerSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MVPlannerSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<MVPlannerSrv-response> is deprecated: use svg_ros-srv:MVPlannerSrv-response instead.")))

(cl:ensure-generic-function 'param-val :lambda-list '(m))
(cl:defmethod param-val ((m <MVPlannerSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:param-val is deprecated.  Use svg_ros-srv:param instead.")
  (param m))

(cl:ensure-generic-function 'coord_x-val :lambda-list '(m))
(cl:defmethod coord_x-val ((m <MVPlannerSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_x-val is deprecated.  Use svg_ros-srv:coord_x instead.")
  (coord_x m))

(cl:ensure-generic-function 'coord_y-val :lambda-list '(m))
(cl:defmethod coord_y-val ((m <MVPlannerSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_y-val is deprecated.  Use svg_ros-srv:coord_y instead.")
  (coord_y m))

(cl:ensure-generic-function 'coord_ang-val :lambda-list '(m))
(cl:defmethod coord_ang-val ((m <MVPlannerSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_ang-val is deprecated.  Use svg_ros-srv:coord_ang instead.")
  (coord_ang m))

(cl:ensure-generic-function 'flgGUI-val :lambda-list '(m))
(cl:defmethod flgGUI-val ((m <MVPlannerSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:flgGUI-val is deprecated.  Use svg_ros-srv:flgGUI instead.")
  (flgGUI m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MVPlannerSrv-response>) ostream)
  "Serializes a message object of type '<MVPlannerSrv-response>"
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
  (cl:let* ((signed (cl:slot-value msg 'flgGUI)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MVPlannerSrv-response>) istream)
  "Deserializes a message object of type '<MVPlannerSrv-response>"
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
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'flgGUI) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MVPlannerSrv-response>)))
  "Returns string type for a service object of type '<MVPlannerSrv-response>"
  "svg_ros/MVPlannerSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MVPlannerSrv-response)))
  "Returns string type for a service object of type 'MVPlannerSrv-response"
  "svg_ros/MVPlannerSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MVPlannerSrv-response>)))
  "Returns md5sum for a message object of type '<MVPlannerSrv-response>"
  "5f074d799916e31d387cc1b1bc10d8d7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MVPlannerSrv-response)))
  "Returns md5sum for a message object of type 'MVPlannerSrv-response"
  "5f074d799916e31d387cc1b1bc10d8d7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MVPlannerSrv-response>)))
  "Returns full string definition for message of type '<MVPlannerSrv-response>"
  (cl:format cl:nil "string param~%float32 coord_x~%float32 coord_y~%float32 coord_ang~%int32 flgGUI~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MVPlannerSrv-response)))
  "Returns full string definition for message of type 'MVPlannerSrv-response"
  (cl:format cl:nil "string param~%float32 coord_x~%float32 coord_y~%float32 coord_ang~%int32 flgGUI~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MVPlannerSrv-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'param))
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MVPlannerSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MVPlannerSrv-response
    (cl:cons ':param (param msg))
    (cl:cons ':coord_x (coord_x msg))
    (cl:cons ':coord_y (coord_y msg))
    (cl:cons ':coord_ang (coord_ang msg))
    (cl:cons ':flgGUI (flgGUI msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MVPlannerSrv)))
  'MVPlannerSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MVPlannerSrv)))
  'MVPlannerSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MVPlannerSrv)))
  "Returns string type for a service object of type '<MVPlannerSrv>"
  "svg_ros/MVPlannerSrv")