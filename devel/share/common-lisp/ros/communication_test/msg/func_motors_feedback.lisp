; Auto-generated. Do not edit!


(cl:in-package communication_test-msg)


;//! \htmlinclude func_motors_feedback.msg.html

(cl:defclass <func_motors_feedback> (roslisp-msg-protocol:ros-message)
  ((Encorder_linearModule
    :reader Encorder_linearModule
    :initarg :Encorder_linearModule
    :type cl:integer
    :initform 0)
   (Hall_putter_1_left
    :reader Hall_putter_1_left
    :initarg :Hall_putter_1_left
    :type cl:integer
    :initform 0)
   (Hall_putter_1_right
    :reader Hall_putter_1_right
    :initarg :Hall_putter_1_right
    :type cl:integer
    :initform 0)
   (Hall_putter_2_left
    :reader Hall_putter_2_left
    :initarg :Hall_putter_2_left
    :type cl:integer
    :initform 0)
   (Hall_putter_2_right
    :reader Hall_putter_2_right
    :initarg :Hall_putter_2_right
    :type cl:integer
    :initform 0)
   (Hall_putter_3_left
    :reader Hall_putter_3_left
    :initarg :Hall_putter_3_left
    :type cl:integer
    :initform 0)
   (Hall_putter_3_right
    :reader Hall_putter_3_right
    :initarg :Hall_putter_3_right
    :type cl:integer
    :initform 0))
)

(cl:defclass func_motors_feedback (<func_motors_feedback>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <func_motors_feedback>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'func_motors_feedback)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name communication_test-msg:<func_motors_feedback> is deprecated: use communication_test-msg:func_motors_feedback instead.")))

(cl:ensure-generic-function 'Encorder_linearModule-val :lambda-list '(m))
(cl:defmethod Encorder_linearModule-val ((m <func_motors_feedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_test-msg:Encorder_linearModule-val is deprecated.  Use communication_test-msg:Encorder_linearModule instead.")
  (Encorder_linearModule m))

(cl:ensure-generic-function 'Hall_putter_1_left-val :lambda-list '(m))
(cl:defmethod Hall_putter_1_left-val ((m <func_motors_feedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_test-msg:Hall_putter_1_left-val is deprecated.  Use communication_test-msg:Hall_putter_1_left instead.")
  (Hall_putter_1_left m))

(cl:ensure-generic-function 'Hall_putter_1_right-val :lambda-list '(m))
(cl:defmethod Hall_putter_1_right-val ((m <func_motors_feedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_test-msg:Hall_putter_1_right-val is deprecated.  Use communication_test-msg:Hall_putter_1_right instead.")
  (Hall_putter_1_right m))

(cl:ensure-generic-function 'Hall_putter_2_left-val :lambda-list '(m))
(cl:defmethod Hall_putter_2_left-val ((m <func_motors_feedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_test-msg:Hall_putter_2_left-val is deprecated.  Use communication_test-msg:Hall_putter_2_left instead.")
  (Hall_putter_2_left m))

(cl:ensure-generic-function 'Hall_putter_2_right-val :lambda-list '(m))
(cl:defmethod Hall_putter_2_right-val ((m <func_motors_feedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_test-msg:Hall_putter_2_right-val is deprecated.  Use communication_test-msg:Hall_putter_2_right instead.")
  (Hall_putter_2_right m))

(cl:ensure-generic-function 'Hall_putter_3_left-val :lambda-list '(m))
(cl:defmethod Hall_putter_3_left-val ((m <func_motors_feedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_test-msg:Hall_putter_3_left-val is deprecated.  Use communication_test-msg:Hall_putter_3_left instead.")
  (Hall_putter_3_left m))

(cl:ensure-generic-function 'Hall_putter_3_right-val :lambda-list '(m))
(cl:defmethod Hall_putter_3_right-val ((m <func_motors_feedback>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication_test-msg:Hall_putter_3_right-val is deprecated.  Use communication_test-msg:Hall_putter_3_right instead.")
  (Hall_putter_3_right m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <func_motors_feedback>) ostream)
  "Serializes a message object of type '<func_motors_feedback>"
  (cl:let* ((signed (cl:slot-value msg 'Encorder_linearModule)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Hall_putter_1_left)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Hall_putter_1_right)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Hall_putter_2_left)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Hall_putter_2_right)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Hall_putter_3_left)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'Hall_putter_3_right)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <func_motors_feedback>) istream)
  "Deserializes a message object of type '<func_motors_feedback>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Encorder_linearModule) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Hall_putter_1_left) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Hall_putter_1_right) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Hall_putter_2_left) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Hall_putter_2_right) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Hall_putter_3_left) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Hall_putter_3_right) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<func_motors_feedback>)))
  "Returns string type for a message object of type '<func_motors_feedback>"
  "communication_test/func_motors_feedback")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'func_motors_feedback)))
  "Returns string type for a message object of type 'func_motors_feedback"
  "communication_test/func_motors_feedback")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<func_motors_feedback>)))
  "Returns md5sum for a message object of type '<func_motors_feedback>"
  "71b9c468b90827306b28dd711ec11502")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'func_motors_feedback)))
  "Returns md5sum for a message object of type 'func_motors_feedback"
  "71b9c468b90827306b28dd711ec11502")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<func_motors_feedback>)))
  "Returns full string definition for message of type '<func_motors_feedback>"
  (cl:format cl:nil "    int32 Encorder_linearModule  ~%    int32 Hall_putter_1_left     ~%    int32 Hall_putter_1_right   ~%    int32 Hall_putter_2_left     ~%    int32 Hall_putter_2_right   ~%    int32 Hall_putter_3_left     ~%    int32 Hall_putter_3_right    ~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'func_motors_feedback)))
  "Returns full string definition for message of type 'func_motors_feedback"
  (cl:format cl:nil "    int32 Encorder_linearModule  ~%    int32 Hall_putter_1_left     ~%    int32 Hall_putter_1_right   ~%    int32 Hall_putter_2_left     ~%    int32 Hall_putter_2_right   ~%    int32 Hall_putter_3_left     ~%    int32 Hall_putter_3_right    ~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <func_motors_feedback>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <func_motors_feedback>))
  "Converts a ROS message object to a list"
  (cl:list 'func_motors_feedback
    (cl:cons ':Encorder_linearModule (Encorder_linearModule msg))
    (cl:cons ':Hall_putter_1_left (Hall_putter_1_left msg))
    (cl:cons ':Hall_putter_1_right (Hall_putter_1_right msg))
    (cl:cons ':Hall_putter_2_left (Hall_putter_2_left msg))
    (cl:cons ':Hall_putter_2_right (Hall_putter_2_right msg))
    (cl:cons ':Hall_putter_3_left (Hall_putter_3_left msg))
    (cl:cons ':Hall_putter_3_right (Hall_putter_3_right msg))
))
