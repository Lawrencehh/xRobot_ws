
(cl:in-package :asdf)

(defsystem "turtlebot_teleop-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "twist_hh" :depends-on ("_package_twist_hh"))
    (:file "_package_twist_hh" :depends-on ("_package"))
  ))