(defun main ())
(defun f ()
	(let (_n _t _ans)
		(setq _n (read))
		(setq _t (read))
		(setq _ans 1000000000)
		(dotimes (i _n)
			(let (tmp_c tmp_t)
				(setq tmp_c (read))
				(setq tmp_t (read))
				(if (<= tmp_t _t)
					(setq _ans (min _ans tmp_c))
					nil
				)
			)
		)
		(if (= _ans 1000000000)
			(format t "TLE~%")
			(format t "~a~%" _ans)
		)
	)
)
(f)
