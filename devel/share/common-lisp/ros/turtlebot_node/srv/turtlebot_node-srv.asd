
(cl:in-package :asdf)

(defsystem "turtlebot_node-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MVServ" :depends-on ("_package_MVServ"))
    (:file "_package_MVServ" :depends-on ("_package"))
  ))