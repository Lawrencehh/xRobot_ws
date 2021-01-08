;; Auto-generated. Do not edit!


(when (boundp 'communication_test::func_motors_feedback)
  (if (not (find-package "COMMUNICATION_TEST"))
    (make-package "COMMUNICATION_TEST"))
  (shadow 'func_motors_feedback (find-package "COMMUNICATION_TEST")))
(unless (find-package "COMMUNICATION_TEST::FUNC_MOTORS_FEEDBACK")
  (make-package "COMMUNICATION_TEST::FUNC_MOTORS_FEEDBACK"))

(in-package "ROS")
;;//! \htmlinclude func_motors_feedback.msg.html


(defclass communication_test::func_motors_feedback
  :super ros::object
  :slots (_Encorder_linearModule _Hall_putter_1_left _Hall_putter_1_right _Hall_putter_2_left _Hall_putter_2_right _Hall_putter_3_left _Hall_putter_3_right ))

(defmethod communication_test::func_motors_feedback
  (:init
   (&key
    ((:Encorder_linearModule __Encorder_linearModule) 0)
    ((:Hall_putter_1_left __Hall_putter_1_left) 0)
    ((:Hall_putter_1_right __Hall_putter_1_right) 0)
    ((:Hall_putter_2_left __Hall_putter_2_left) 0)
    ((:Hall_putter_2_right __Hall_putter_2_right) 0)
    ((:Hall_putter_3_left __Hall_putter_3_left) 0)
    ((:Hall_putter_3_right __Hall_putter_3_right) 0)
    )
   (send-super :init)
   (setq _Encorder_linearModule (round __Encorder_linearModule))
   (setq _Hall_putter_1_left (round __Hall_putter_1_left))
   (setq _Hall_putter_1_right (round __Hall_putter_1_right))
   (setq _Hall_putter_2_left (round __Hall_putter_2_left))
   (setq _Hall_putter_2_right (round __Hall_putter_2_right))
   (setq _Hall_putter_3_left (round __Hall_putter_3_left))
   (setq _Hall_putter_3_right (round __Hall_putter_3_right))
   self)
  (:Encorder_linearModule
   (&optional __Encorder_linearModule)
   (if __Encorder_linearModule (setq _Encorder_linearModule __Encorder_linearModule)) _Encorder_linearModule)
  (:Hall_putter_1_left
   (&optional __Hall_putter_1_left)
   (if __Hall_putter_1_left (setq _Hall_putter_1_left __Hall_putter_1_left)) _Hall_putter_1_left)
  (:Hall_putter_1_right
   (&optional __Hall_putter_1_right)
   (if __Hall_putter_1_right (setq _Hall_putter_1_right __Hall_putter_1_right)) _Hall_putter_1_right)
  (:Hall_putter_2_left
   (&optional __Hall_putter_2_left)
   (if __Hall_putter_2_left (setq _Hall_putter_2_left __Hall_putter_2_left)) _Hall_putter_2_left)
  (:Hall_putter_2_right
   (&optional __Hall_putter_2_right)
   (if __Hall_putter_2_right (setq _Hall_putter_2_right __Hall_putter_2_right)) _Hall_putter_2_right)
  (:Hall_putter_3_left
   (&optional __Hall_putter_3_left)
   (if __Hall_putter_3_left (setq _Hall_putter_3_left __Hall_putter_3_left)) _Hall_putter_3_left)
  (:Hall_putter_3_right
   (&optional __Hall_putter_3_right)
   (if __Hall_putter_3_right (setq _Hall_putter_3_right __Hall_putter_3_right)) _Hall_putter_3_right)
  (:serialization-length
   ()
   (+
    ;; int32 _Encorder_linearModule
    4
    ;; int32 _Hall_putter_1_left
    4
    ;; int32 _Hall_putter_1_right
    4
    ;; int32 _Hall_putter_2_left
    4
    ;; int32 _Hall_putter_2_right
    4
    ;; int32 _Hall_putter_3_left
    4
    ;; int32 _Hall_putter_3_right
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _Encorder_linearModule
       (write-long _Encorder_linearModule s)
     ;; int32 _Hall_putter_1_left
       (write-long _Hall_putter_1_left s)
     ;; int32 _Hall_putter_1_right
       (write-long _Hall_putter_1_right s)
     ;; int32 _Hall_putter_2_left
       (write-long _Hall_putter_2_left s)
     ;; int32 _Hall_putter_2_right
       (write-long _Hall_putter_2_right s)
     ;; int32 _Hall_putter_3_left
       (write-long _Hall_putter_3_left s)
     ;; int32 _Hall_putter_3_right
       (write-long _Hall_putter_3_right s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _Encorder_linearModule
     (setq _Encorder_linearModule (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Hall_putter_1_left
     (setq _Hall_putter_1_left (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Hall_putter_1_right
     (setq _Hall_putter_1_right (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Hall_putter_2_left
     (setq _Hall_putter_2_left (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Hall_putter_2_right
     (setq _Hall_putter_2_right (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Hall_putter_3_left
     (setq _Hall_putter_3_left (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _Hall_putter_3_right
     (setq _Hall_putter_3_right (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get communication_test::func_motors_feedback :md5sum-) "71b9c468b90827306b28dd711ec11502")
(setf (get communication_test::func_motors_feedback :datatype-) "communication_test/func_motors_feedback")
(setf (get communication_test::func_motors_feedback :definition-)
      "    int32 Encorder_linearModule  
    int32 Hall_putter_1_left     
    int32 Hall_putter_1_right   
    int32 Hall_putter_2_left     
    int32 Hall_putter_2_right   
    int32 Hall_putter_3_left     
    int32 Hall_putter_3_right    
")



(provide :communication_test/func_motors_feedback "71b9c468b90827306b28dd711ec11502")


