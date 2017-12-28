; Auto-generated. Do not edit!


(cl:in-package svg_ros-srv)


;//! \htmlinclude SensorSrv-request.msg.html

(cl:defclass <SensorSrv-request> (roslisp-msg-protocol:ros-message)
  ((coord_x
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

(cl:defclass SensorSrv-request (<SensorSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SensorSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SensorSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<SensorSrv-request> is deprecated: use svg_ros-srv:SensorSrv-request instead.")))

(cl:ensure-generic-function 'coord_x-val :lambda-list '(m))
(cl:defmethod coord_x-val ((m <SensorSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_x-val is deprecated.  Use svg_ros-srv:coord_x instead.")
  (coord_x m))

(cl:ensure-generic-function 'coord_y-val :lambda-list '(m))
(cl:defmethod coord_y-val ((m <SensorSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_y-val is deprecated.  Use svg_ros-srv:coord_y instead.")
  (coord_y m))

(cl:ensure-generic-function 'coord_ang-val :lambda-list '(m))
(cl:defmethod coord_ang-val ((m <SensorSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_ang-val is deprecated.  Use svg_ros-srv:coord_ang instead.")
  (coord_ang m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SensorSrv-request>) ostream)
  "Serializes a message object of type '<SensorSrv-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SensorSrv-request>) istream)
  "Deserializes a message object of type '<SensorSrv-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SensorSrv-request>)))
  "Returns string type for a service object of type '<SensorSrv-request>"
  "svg_ros/SensorSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SensorSrv-request)))
  "Returns string type for a service object of type 'SensorSrv-request"
  "svg_ros/SensorSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SensorSrv-request>)))
  "Returns md5sum for a message object of type '<SensorSrv-request>"
  "b3a08c1472f241ab9eb4c0932b73ff18")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SensorSrv-request)))
  "Returns md5sum for a message object of type 'SensorSrv-request"
  "b3a08c1472f241ab9eb4c0932b73ff18")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SensorSrv-request>)))
  "Returns full string definition for message of type '<SensorSrv-request>"
  (cl:format cl:nil "float32 coord_x~%float32 coord_y~%float32 coord_ang~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SensorSrv-request)))
  "Returns full string definition for message of type 'SensorSrv-request"
  (cl:format cl:nil "float32 coord_x~%float32 coord_y~%float32 coord_ang~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SensorSrv-request>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SensorSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SensorSrv-request
    (cl:cons ':coord_x (coord_x msg))
    (cl:cons ':coord_y (coord_y msg))
    (cl:cons ':coord_ang (coord_ang msg))
))
;//! \htmlinclude SensorSrv-response.msg.html

(cl:defclass <SensorSrv-response> (roslisp-msg-protocol:ros-message)
  ((flag
    :reader flag
    :initarg :flag
    :type cl:integer
    :initform 0)
   (region
    :reader region
    :initarg :region
    :type cl:integer
    :initform 0)
   (x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (theta
    :reader theta
    :initarg :theta
    :type cl:float
    :initform 0.0)
   (sensors
    :reader sensors
    :initarg :sensors
    :type (cl:vector cl:float)
   :initform (cl:make-array 500 :element-type 'cl:float :initial-element 0.0))
   (num_sensors
    :reader num_sensors
    :initarg :num_sensors
    :type cl:integer
    :initform 0)
   (sensor
    :reader sensor
    :initarg :sensor
    :type cl:string
    :initform ""))
)

(cl:defclass SensorSrv-response (<SensorSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SensorSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SensorSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<SensorSrv-response> is deprecated: use svg_ros-srv:SensorSrv-response instead.")))

(cl:ensure-generic-function 'flag-val :lambda-list '(m))
(cl:defmethod flag-val ((m <SensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:flag-val is deprecated.  Use svg_ros-srv:flag instead.")
  (flag m))

(cl:ensure-generic-function 'region-val :lambda-list '(m))
(cl:defmethod region-val ((m <SensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:region-val is deprecated.  Use svg_ros-srv:region instead.")
  (region m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <SensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:x-val is deprecated.  Use svg_ros-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <SensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:y-val is deprecated.  Use svg_ros-srv:y instead.")
  (y m))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <SensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:theta-val is deprecated.  Use svg_ros-srv:theta instead.")
  (theta m))

(cl:ensure-generic-function 'sensors-val :lambda-list '(m))
(cl:defmethod sensors-val ((m <SensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:sensors-val is deprecated.  Use svg_ros-srv:sensors instead.")
  (sensors m))

(cl:ensure-generic-function 'num_sensors-val :lambda-list '(m))
(cl:defmethod num_sensors-val ((m <SensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:num_sensors-val is deprecated.  Use svg_ros-srv:num_sensors instead.")
  (num_sensors m))

(cl:ensure-generic-function 'sensor-val :lambda-list '(m))
(cl:defmethod sensor-val ((m <SensorSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:sensor-val is deprecated.  Use svg_ros-srv:sensor instead.")
  (sensor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SensorSrv-response>) ostream)
  "Serializes a message object of type '<SensorSrv-response>"
  (cl:let* ((signed (cl:slot-value msg 'flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'region)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'theta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'sensors))
  (cl:let* ((signed (cl:slot-value msg 'num_sensors)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'sensor))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'sensor))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SensorSrv-response>) istream)
  "Deserializes a message object of type '<SensorSrv-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'flag) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'region) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'theta) (roslisp-utils:decode-single-float-bits bits)))
  (cl:setf (cl:slot-value msg 'sensors) (cl:make-array 500))
  (cl:let ((vals (cl:slot-value msg 'sensors)))
    (cl:dotimes (i 500)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'num_sensors) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sensor) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'sensor) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SensorSrv-response>)))
  "Returns string type for a service object of type '<SensorSrv-response>"
  "svg_ros/SensorSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SensorSrv-response)))
  "Returns string type for a service object of type 'SensorSrv-response"
  "svg_ros/SensorSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SensorSrv-response>)))
  "Returns md5sum for a message object of type '<SensorSrv-response>"
  "b3a08c1472f241ab9eb4c0932b73ff18")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SensorSrv-response)))
  "Returns md5sum for a message object of type 'SensorSrv-response"
  "b3a08c1472f241ab9eb4c0932b73ff18")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SensorSrv-response>)))
  "Returns full string definition for message of type '<SensorSrv-response>"
  (cl:format cl:nil "int32 flag~%int32 region~%float32 x~%float32 y~%float32 theta~%float32[500] sensors~%int32 num_sensors~%string sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SensorSrv-response)))
  "Returns full string definition for message of type 'SensorSrv-response"
  (cl:format cl:nil "int32 flag~%int32 region~%float32 x~%float32 y~%float32 theta~%float32[500] sensors~%int32 num_sensors~%string sensor~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SensorSrv-response>))
  (cl:+ 0
     4
     4
     4
     4
     4
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'sensors) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     4 (cl:length (cl:slot-value msg 'sensor))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SensorSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SensorSrv-response
    (cl:cons ':flag (flag msg))
    (cl:cons ':region (region msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':theta (theta msg))
    (cl:cons ':sensors (sensors msg))
    (cl:cons ':num_sensors (num_sensors msg))
    (cl:cons ':sensor (sensor msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SensorSrv)))
  'SensorSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SensorSrv)))
  'SensorSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SensorSrv)))
  "Returns string type for a service object of type '<SensorSrv>"
  "svg_ros/SensorSrv")