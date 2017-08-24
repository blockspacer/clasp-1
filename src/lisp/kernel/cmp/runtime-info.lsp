(in-package #:cmp)

(defvar +header-size+ 8) ; FIXME: where does this come from?


(defvar +cxx-data-structures-info+ (llvm-sys:cxx-data-structures-info))

(defun get-cxx-data-structure-info (name &optional (info +cxx-data-structures-info+))
  (let ((find (assoc name info)))
    (or find (error "Could not find ~a in cxx-data-structures-info --> ~s~%" name info))
    (cdr find)))
(defvar +register-save-area-size+ (get-cxx-data-structure-info :register-save-area-size))
(defvar +void*-size+ (get-cxx-data-structure-info :void*-size))
(defvar +value-frame-parent-offset+ (get-cxx-data-structure-info :value-frame-parent-offset))
(defvar +closure-entry-point-offset+ (get-cxx-data-structure-info :closure-entry-point-offset))
(defvar +valist_s-remaining-nargs-offset+ (get-cxx-data-structure-info :valist_s-remaining-nargs-offset))
(defvar +fixnum-stamp+ (get-cxx-data-structure-info :fixnum-stamp))
(defvar +cons-stamp+ (get-cxx-data-structure-info :cons-stamp))
(defvar +valist_s-stamp+ (get-cxx-data-structure-info :va_list_s-stamp))
(defvar +character-stamp+ (get-cxx-data-structure-info :character-stamp))
(defvar +single-float-stamp+ (get-cxx-data-structure-info :single-float-stamp))
(defvar +instance-rack-stamp-offset+ (get-cxx-data-structure-info :instance-rack-stamp-offset))
(defvar +instance-rack-offset+ (get-cxx-data-structure-info :instance-rack-offset))
(defvar +instance-kind+ (get-cxx-data-structure-info :instance-kind))
(defvar +funcallable-instance-kind+ (get-cxx-data-structure-info :funcallable-instance-kind))
(defvar +header-size+ (get-cxx-data-structure-info :header-size))
(defvar +fixnum-mask+ (get-cxx-data-structure-info :fixnum-mask))
(defvar +fixnum-shift+ (get-cxx-data-structure-info :fixnum-shift))
;;(error "kind-shift is not defined anymore - it's :stamp-shift and :stamp-in-rack-mask and :stamp-needs-call-mask")
(defvar +stamp-shift+ (get-cxx-data-structure-info :stamp-shift))
(defvar +stamp-in-rack-mask+ (get-cxx-data-structure-info :stamp-in-rack-mask))
(defvar +stamp-needs-call-mask+ (get-cxx-data-structure-info :stamp-needs-call-mask))
(defvar +tag-mask+ (get-cxx-data-structure-info :tag-mask))
(defvar +immediate-mask+ (get-cxx-data-structure-info :immediate-mask))
(defvar +cons-tag+ (get-cxx-data-structure-info :cons-tag))
(defvar +VaList_S-tag+ (get-cxx-data-structure-info :valist-tag))
(defvar +fixnum-tag+ (get-cxx-data-structure-info :fixnum-tag))
(defvar +fixnum1-tag+ (get-cxx-data-structure-info :fixnum1-tag))
(defvar +character-tag+ (get-cxx-data-structure-info :character-tag))
(defvar +single-float-tag+ (get-cxx-data-structure-info :single-float-tag))
(defvar +general-tag+ (get-cxx-data-structure-info :general-tag))
(defvar +VaList_S-size+ (get-cxx-data-structure-info :VaList_S-size))
(defvar +VaList_S-valist-offset+ (get-cxx-data-structure-info :VaList_S-valist-offset))
(defvar +VaList_S-remaining-nargs-offset+ (get-cxx-data-structure-info :VaList_S-remaining-nargs-offset))
(defvar +void*-size+ (get-cxx-data-structure-info :void*-size))
(defvar +alignment+ (get-cxx-data-structure-info :alignment))
(defvar +args-in-registers+ (get-cxx-data-structure-info :lcc-args-in-registers))
(export '(+fixnum-mask+ +tag-mask+ +immediate-mask+
          +cons-tag+ +fixnum-tag+ +character-tag+ +single-float-tag+
          +general-tag+ +VaList_S-size+ +void*-size+ +alignment+ ))
(defvar +cons-car-offset+ (get-cxx-data-structure-info :cons-car-offset))
(defvar +cons-cdr-offset+ (get-cxx-data-structure-info :cons-cdr-offset))
(defvar +uintptr_t-size+ (get-cxx-data-structure-info :uintptr_t-size))
(defvar +t-size+ (get-cxx-data-structure-info 'core:tsp))
(defvar +simple-vector._length-offset+ (get-cxx-data-structure-info :simple-vector._length-offset))
(defvar +simple-vector._data-offset+ (get-cxx-data-structure-info :simple-vector._data-offset))
