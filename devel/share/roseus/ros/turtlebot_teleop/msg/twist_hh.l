;; Auto-generated. Do not edit!


(when (boundp 'turtlebot_teleop::twist_hh)
  (if (not (find-package "TURTLEBOT_TELEOP"))
    (make-package "TURTLEBOT_TELEOP"))
  (shadow 'twist_hh (find-package "TURTLEBOT_TELEOP")))
(unless (find-package "TURTLEBOT_TELEOP::TWIST_HH")
  (make-package "TURTLEBOT_TELEOP::TWIST_HH"))

(in-package "ROS")
;;//! \htmlinclude twist_hh.msg.html


(defclass turtlebot_teleop::twist_hh
  :super ros::object
  :slots (_linear_module _putter_1 _putter_2 _oblique_angle _oblique_drawer _flat_drawer _belt _camera_angle _camera_tilt _arm_auto ))

(defmethod turtlebot_teleop::twist_hh
  (:init
   (&key
    ((:linear_module __linear_module) 0.0)
    ((:putter_1 __putter_1) 0.0)
    ((:putter_2 __putter_2) 0.0)
    ((:oblique_angle __oblique_angle) 0.0)
    ((:oblique_drawer __oblique_drawer) 0)
    ((:flat_drawer __flat_drawer) 0)
    ((:belt __belt) 0)
    ((:camera_angle __camera_angle) 0)
    ((:camera_tilt __camera_tilt) 0)
    ((:arm_auto __arm_auto) 0)
    )
   (send-super :init)
   (setq _linear_module (float __linear_module))
   (setq _putter_1 (float __putter_1))
   (setq _putter_2 (float __putter_2))
   (setq _oblique_angle (float __oblique_angle))
   (setq _oblique_drawer (round __oblique_drawer))
   (setq _flat_drawer (round __flat_drawer))
   (setq _belt (round __belt))
   (setq _camera_angle (round __camera_angle))
   (setq _camera_tilt (round __camera_tilt))
   (setq _arm_auto (round __arm_auto))
   self)
  (:linear_module
   (&optional __linear_module)
   (if __linear_module (setq _linear_module __linear_module)) _linear_module)
  (:putter_1
   (&optional __putter_1)
   (if __putter_1 (setq _putter_1 __putter_1)) _putter_1)
  (:putter_2
   (&optional __putter_2)
   (if __putter_2 (setq _putter_2 __putter_2)) _putter_2)
  (:oblique_angle
   (&optional __oblique_angle)
   (if __oblique_angle (setq _oblique_angle __oblique_angle)) _oblique_angle)
  (:oblique_drawer
   (&optional __oblique_drawer)
   (if __oblique_drawer (setq _oblique_drawer __oblique_drawer)) _oblique_drawer)
  (:flat_drawer
   (&optional __flat_drawer)
   (if __flat_drawer (setq _flat_drawer __flat_drawer)) _flat_drawer)
  (:belt
   (&optional __belt)
   (if __belt (setq _belt __belt)) _belt)
  (:camera_angle
   (&optional __camera_angle)
   (if __camera_angle (setq _camera_angle __camera_angle)) _camera_angle)
  (:camera_tilt
   (&optional __camera_tilt)
   (if __camera_tilt (setq _camera_tilt __camera_tilt)) _camera_tilt)
  (:arm_auto
   (&optional __arm_auto)
   (if __arm_auto (setq _arm_auto __arm_auto)) _arm_auto)
  (:serialization-length
   ()
   (+
    ;; float32 _linear_module
    4
    ;; float32 _putter_1
    4
    ;; float32 _putter_2
    4
    ;; float32 _oblique_angle
    4
    ;; int8 _oblique_drawer
    1
    ;; int8 _flat_drawer
    1
    ;; uint8 _belt
    1
    ;; int8 _camera_angle
    1
    ;; int8 _camera_tilt
    1
    ;; int8 _arm_auto
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _linear_module
       (sys::poke _linear_module (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _putter_1
       (sys::poke _putter_1 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _putter_2
       (sys::poke _putter_2 (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _oblique_angle
       (sys::poke _oblique_angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int8 _oblique_drawer
       (write-byte _oblique_drawer s)
     ;; int8 _flat_drawer
       (write-byte _flat_drawer s)
     ;; uint8 _belt
       (write-byte _belt s)
     ;; int8 _camera_angle
       (write-byte _camera_angle s)
     ;; int8 _camera_tilt
       (write-byte _camera_tilt s)
     ;; int8 _arm_auto
       (write-byte _arm_auto s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _linear_module
     (setq _linear_module (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _putter_1
     (setq _putter_1 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _putter_2
     (setq _putter_2 (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _oblique_angle
     (setq _oblique_angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int8 _oblique_drawer
     (setq _oblique_drawer (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _oblique_drawer 127) (setq _oblique_drawer (- _oblique_drawer 256)))
   ;; int8 _flat_drawer
     (setq _flat_drawer (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _flat_drawer 127) (setq _flat_drawer (- _flat_drawer 256)))
   ;; uint8 _belt
     (setq _belt (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int8 _camera_angle
     (setq _camera_angle (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _camera_angle 127) (setq _camera_angle (- _camera_angle 256)))
   ;; int8 _camera_tilt
     (setq _camera_tilt (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _camera_tilt 127) (setq _camera_tilt (- _camera_tilt 256)))
   ;; int8 _arm_auto
     (setq _arm_auto (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _arm_auto 127) (setq _arm_auto (- _arm_auto 256)))
   ;;
   self)
  )

(setf (get turtlebot_teleop::twist_hh :md5sum-) "5e6950298e015b052c3449e8eabb1ac3")
(setf (get turtlebot_teleop::twist_hh :datatype-) "turtlebot_teleop/twist_hh")
(setf (get turtlebot_teleop::twist_hh :definition-)
      "# This expresses velocity in free space broken into its linear and angular parts.



float32 linear_module
float32 putter_1
float32 putter_2

float32 oblique_angle
int8 oblique_drawer
int8 flat_drawer

uint8 belt
int8 camera_angle
int8 camera_tilt

int8 arm_auto
")



(provide :turtlebot_teleop/twist_hh "5e6950298e015b052c3449e8eabb1ac3")


