; Auto-generated. Do not edit!


(cl:in-package svg_ros-srv)


;//! \htmlinclude LightSrv-request.msg.html

(cl:defclass <LightSrv-request> (roslisp-msg-protocol:ros-message)
  ((req
    :reader req
    :initarg :req
    :type cl:integer
    :initform 0)
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

(cl:defclass LightSrv-request (<LightSrv-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LightSrv-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LightSrv-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<LightSrv-request> is deprecated: use svg_ros-srv:LightSrv-request instead.")))

(cl:ensure-generic-function 'req-val :lambda-list '(m))
(cl:defmethod req-val ((m <LightSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:req-val is deprecated.  Use svg_ros-srv:req instead.")
  (req m))

(cl:ensure-generic-function 'coord_x-val :lambda-list '(m))
(cl:defmethod coord_x-val ((m <LightSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_x-val is deprecated.  Use svg_ros-srv:coord_x instead.")
  (coord_x m))

(cl:ensure-generic-function 'coord_y-val :lambda-list '(m))
(cl:defmethod coord_y-val ((m <LightSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_y-val is deprecated.  Use svg_ros-srv:coord_y instead.")
  (coord_y m))

(cl:ensure-generic-function 'coord_ang-val :lambda-list '(m))
(cl:defmethod coord_ang-val ((m <LightSrv-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:coord_ang-val is deprecated.  Use svg_ros-srv:coord_ang instead.")
  (coord_ang m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LightSrv-request>) ostream)
  "Serializes a message object of type '<LightSrv-request>"
  (cl:let* ((signed (cl:slot-value msg 'req)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LightSrv-request>) istream)
  "Deserializes a message object of type '<LightSrv-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'req) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LightSrv-request>)))
  "Returns string type for a service object of type '<LightSrv-request>"
  "svg_ros/LightSrvRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LightSrv-request)))
  "Returns string type for a service object of type 'LightSrv-request"
  "svg_ros/LightSrvRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LightSrv-request>)))
  "Returns md5sum for a message object of type '<LightSrv-request>"
  "eba6c43e856487b2b6ad559a0d0f124d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LightSrv-request)))
  "Returns md5sum for a message object of type 'LightSrv-request"
  "eba6c43e856487b2b6ad559a0d0f124d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LightSrv-request>)))
  "Returns full string definition for message of type '<LightSrv-request>"
  (cl:format cl:nil "int32 req~%float32 coord_x~%float32 coord_y~%float32 coord_ang~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LightSrv-request)))
  "Returns full string definition for message of type 'LightSrv-request"
  (cl:format cl:nil "int32 req~%float32 coord_x~%float32 coord_y~%float32 coord_ang~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LightSrv-request>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LightSrv-request>))
  "Converts a ROS message object to a list"
  (cl:list 'LightSrv-request
    (cl:cons ':req (req msg))
    (cl:cons ':coord_x (coord_x msg))
    (cl:cons ':coord_y (coord_y msg))
    (cl:cons ':coord_ang (coord_ang msg))
))
;//! \htmlinclude LightSrv-response.msg.html

(cl:defclass <LightSrv-response> (roslisp-msg-protocol:ros-message)
  ((flag_dest
    :reader flag_dest
    :initarg :flag_dest
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
   (quantized_attraction
    :reader quantized_attraction
    :initarg :quantized_attraction
    :type cl:integer
    :initform 0)
   (quantized_intensity
    :reader quantized_intensity
    :initarg :quantized_intensity
    :type cl:integer
    :initform 0))
)

(cl:defclass LightSrv-response (<LightSrv-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LightSrv-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LightSrv-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name svg_ros-srv:<LightSrv-response> is deprecated: use svg_ros-srv:LightSrv-response instead.")))

(cl:ensure-generic-function 'flag_dest-val :lambda-list '(m))
(cl:defmethod flag_dest-val ((m <LightSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:flag_dest-val is deprecated.  Use svg_ros-srv:flag_dest instead.")
  (flag_dest m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <LightSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:x-val is deprecated.  Use svg_ros-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <LightSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:y-val is deprecated.  Use svg_ros-srv:y instead.")
  (y m))

(cl:ensure-generic-function 'quantized_attraction-val :lambda-list '(m))
(cl:defmethod quantized_attraction-val ((m <LightSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:quantized_attraction-val is deprecated.  Use svg_ros-srv:quantized_attraction instead.")
  (quantized_attraction m))

(cl:ensure-generic-function 'quantized_intensity-val :lambda-list '(m))
(cl:defmethod quantized_intensity-val ((m <LightSrv-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader svg_ros-srv:quantized_intensity-val is deprecated.  Use svg_ros-srv:quantized_intensity instead.")
  (quantized_intensity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LightSrv-response>) ostream)
  "Serializes a message object of type '<LightSrv-response>"
  (cl:let* ((signed (cl:slot-value msg 'flag_dest)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
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
  (cl:let* ((signed (cl:slot-value msg 'quantized_attraction)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'quantized_intensity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LightSrv-response>) istream)
  "Deserializes a message object of type '<LightSrv-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'flag_dest) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
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
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'quantized_attraction) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'quantized_intensity) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LightSrv-response>)))
  "Returns string type for a service object of type '<LightSrv-response>"
  "svg_ros/LightSrvResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LightSrv-response)))
  "Returns string type for a service object of type 'LightSrv-response"
  "svg_ros/LightSrvResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LightSrv-response>)))
  "Returns md5sum for a message object of type '<LightSrv-response>"
  "eba6c43e856487b2b6ad559a0d0f124d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LightSrv-response)))
  "Returns md5sum for a message object of type 'LightSrv-response"
  "eba6c43e856487b2b6ad559a0d0f124d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LightSrv-response>)))
  "Returns full string definition for message of type '<LightSrv-response>"
  (cl:format cl:nil "int32 flag_dest~%float32 x~%float32 y~%int32 quantized_attraction~%int32 quantized_intensity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LightSrv-response)))
  "Returns full string definition for message of type 'LightSrv-response"
  (cl:format cl:nil "int32 flag_dest~%float32 x~%float32 y~%int32 quantized_attraction~%int32 quantized_intensity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LightSrv-response>))
  (cl:+ 0
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LightSrv-response>))
  "Converts a ROS message object to a list"
  (cl:list 'LightSrv-response
    (cl:cons ':flag_dest (flag_dest msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':quantized_attraction (quantized_attraction msg))
    (cl:cons ':quantized_intensity (quantized_intensity msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'LightSrv)))
  'LightSrv-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'LightSrv)))
  'LightSrv-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LightSrv)))
  "Returns string type for a service object of type '<LightSrv>"
  "svg_ros/LightSrv")