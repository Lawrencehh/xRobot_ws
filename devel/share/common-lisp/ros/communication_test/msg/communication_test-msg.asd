
(cl:in-package :asdf)

(defsystem "communication_test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "func_motors_feedback" :depends-on ("_package_func_motors_feedback"))
    (:file "_package_func_motors_feedback" :depends-on ("_package"))
  ))