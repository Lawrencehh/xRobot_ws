; Auto-generated. Do not edit!


(cl:in-package turtlebot_teleop-msg)


;//! \htmlinclude twist_hh.msg.html

(cl:defclass <twist_hh> (roslisp-msg-protocol:ros-message)
  ((linear_module
    :reader linear_module
    :initarg :linear_module
    :type cl:float
    :initform 0.0)
   (putter_1
    :reader putter_1
    :initarg :putter_1
    :type cl:float
    :initform 0.0)
   (putter_2
    :reader putter_2
    :initarg :putter_2
    :type cl:float
    :initform 0.0)
   (oblique_angle
    :reader oblique_angle
    :initarg :oblique_angle
    :type cl:fixnum
    :initform 0)
   (oblique_drawer
    :reader oblique_drawer
    :initarg :oblique_drawer
    :type cl:fixnum
    :initform 0)
   (flat_drawer
    :reader flat_drawer
    :initarg :flat_drawer
    :type cl:fixnum
    :initform 0)
   (belt
    :reader belt
    :initarg :belt
    :type cl:fixnum
    :initform 0)
   (camera_angle
    :reader camera_angle
    :initarg :camera_angle
    :type cl:fixnum
    :initform 0)
   (camera_tilt
    :reader camera_tilt
    :initarg :camera_tilt
    :type cl:fixnum
    :initform 0))
)

(cl:defclass twist_hh (<twist_hh>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <twist_hh>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'twist_hh)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name turtlebot_teleop-msg:<twist_hh> is deprecated: use turtlebot_teleop-msg:twist_hh instead.")))

(cl:ensure-generic-function 'linear_module-val :lambda-list '(m))
(cl:defmethod linear_module-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:linear_module-val is deprecated.  Use turtlebot_teleop-msg:linear_module instead.")
  (linear_module m))

(cl:ensure-generic-function 'putter_1-val :lambda-list '(m))
(cl:defmethod putter_1-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:putter_1-val is deprecated.  Use turtlebot_teleop-msg:putter_1 instead.")
  (putter_1 m))

(cl:ensure-generic-function 'putter_2-val :lambda-list '(m))
(cl:defmethod putter_2-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:putter_2-val is deprecated.  Use turtlebot_teleop-msg:putter_2 instead.")
  (putter_2 m))

(cl:ensure-generic-function 'oblique_angle-val :lambda-list '(m))
(cl:defmethod oblique_angle-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:oblique_angle-val is deprecated.  Use turtlebot_teleop-msg:oblique_angle instead.")
  (oblique_angle m))

(cl:ensure-generic-function 'oblique_drawer-val :lambda-list '(m))
(cl:defmethod oblique_drawer-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:oblique_drawer-val is deprecated.  Use turtlebot_teleop-msg:oblique_drawer instead.")
  (oblique_drawer m))

(cl:ensure-generic-function 'flat_drawer-val :lambda-list '(m))
(cl:defmethod flat_drawer-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:flat_drawer-val is deprecated.  Use turtlebot_teleop-msg:flat_drawer instead.")
  (flat_drawer m))

(cl:ensure-generic-function 'belt-val :lambda-list '(m))
(cl:defmethod belt-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:belt-val is deprecated.  Use turtlebot_teleop-msg:belt instead.")
  (belt m))

(cl:ensure-generic-function 'camera_angle-val :lambda-list '(m))
(cl:defmethod camera_angle-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:camera_angle-val is deprecated.  Use turtlebot_teleop-msg:camera_angle instead.")
  (camera_angle m))

(cl:ensure-generic-function 'camera_tilt-val :lambda-list '(m))
(cl:defmethod camera_tilt-val ((m <twist_hh>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader turtlebot_teleop-msg:camera_tilt-val is deprecated.  Use turtlebot_teleop-msg:camera_tilt instead.")
  (camera_tilt m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <twist_hh>) ostream)
  "Serializes a message object of type '<twist_hh>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'linear_module))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'putter_1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'putter_2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'oblique_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'oblique_drawer)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'flat_drawer)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'belt)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'camera_angle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'camera_tilt)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <twist_hh>) istream)
  "Deserializes a message object of type '<twist_hh>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'linear_module) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'putter_1) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'putter_2) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'oblique_angle) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'oblique_drawer) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'flat_drawer) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'belt)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'camera_angle) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'camera_tilt) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<twist_hh>)))
  "Returns string type for a message object of type '<twist_hh>"
  "turtlebot_teleop/twist_hh")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'twist_hh)))
  "Returns string type for a message object of type 'twist_hh"
  "turtlebot_teleop/twist_hh")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<twist_hh>)))
  "Returns md5sum for a message object of type '<twist_hh>"
  "18a62653abd37f23cf97caba6719e246")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'twist_hh)))
  "Returns md5sum for a message object of type 'twist_hh"
  "18a62653abd37f23cf97caba6719e246")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<twist_hh>)))
  "Returns full string definition for message of type '<twist_hh>"
  (cl:format cl:nil "# This expresses velocity in free space broken into its linear and angular parts.~%~%~%~%float32 linear_module~%float32 putter_1~%float32 putter_2~%~%int8 oblique_angle~%int8 oblique_drawer~%int8 flat_drawer~%~%uint8 belt~%int8 camera_angle~%int8 camera_tilt~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'twist_hh)))
  "Returns full string definition for message of type 'twist_hh"
  (cl:format cl:nil "# This expresses velocity in free space broken into its linear and angular parts.~%~%~%~%float32 linear_module~%float32 putter_1~%float32 putter_2~%~%int8 oblique_angle~%int8 oblique_drawer~%int8 flat_drawer~%~%uint8 belt~%int8 camera_angle~%int8 camera_tilt~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <twist_hh>))
  (cl:+ 0
     4
     4
     4
     1
     1
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <twist_hh>))
  "Converts a ROS message object to a list"
  (cl:list 'twist_hh
    (cl:cons ':linear_module (linear_module msg))
    (cl:cons ':putter_1 (putter_1 msg))
    (cl:cons ':putter_2 (putter_2 msg))
    (cl:cons ':oblique_angle (oblique_angle msg))
    (cl:cons ':oblique_drawer (oblique_drawer msg))
    (cl:cons ':flat_drawer (flat_drawer msg))
    (cl:cons ':belt (belt msg))
    (cl:cons ':camera_angle (camera_angle msg))
    (cl:cons ':camera_tilt (camera_tilt msg))
))
