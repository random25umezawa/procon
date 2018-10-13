(defun main ())
(defparameter *n* (read))
(print *n*)
(defparameter *x-y-h*
	(loop repeat *n*
		collect ( list (read) (read) (read) )
	)
)
(print *x-y-h*)



(defmacro setxyh (xyh)
	`(loop for val in ,xyh
		for var in '(x y h)
		do (setq var val)
	)
)
(defmacro loopxyh (func &body body)
	`(loop for xyh in *x-y-h*
		do (progn
			(setxyh xyh)
			(,func ,@body)
		)
	)
)

(print
	(macroexpand-1
		'(loopxyh progn
			(print x)
		)
	)
)
;(setxyh '(1 2 3))
;(print x)

(loopxyh progn
	(print x)
)
