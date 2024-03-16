
(cl:in-package :asdf)

(defsystem "test01-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Add" :depends-on ("_package_Add"))
    (:file "_package_Add" :depends-on ("_package"))
  ))