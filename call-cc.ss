(define call/cc call-with-current-continuation)

(define proc
  (lambda () 
    (let ((halt (call/cc (lambda (k) k))))
      (if (procedure? halt)
	  (letrec ((looper 
		    (lambda (n)
		      (if (= n 1000) 
			  (halt n) 
			  (looper (+ n 1))))))
	    (looper 1))
	  halt))))

(define res1 (proc))

(define amb-fail '())

(define amb
  (lambda () 
    (call/cc 
     (lambda (sk)
       (call/cc 
	(lambda (fk1)
	  (set! amb-fail (lambda () (fk1 'fail)))
	  (sk 1)))
       (call/cc 
	(lambda (fk2)
	  (set! amb-fail (lambda () (fk2 'fail)))
	  (sk 2)))
       (call/cc 
	(lambda (fk3)
	  (set! amb-fail (lambda () (fk3 'fail)))
	  (sk 3)))))))

(define back (lambda () (amb-fail)))

(define a (amb))
;; a
;; (back)
;; a

