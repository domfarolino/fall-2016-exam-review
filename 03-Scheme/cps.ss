;; stream:  (first object in list . procedure giving remaining objects in list)

(define s1 
  (cons 2 (lambda () (cons 5 (lambda () (cons 10 (lambda () '())))))))

(define s2 
  (cons 1 (lambda () (cons 7 (lambda () (cons 9 (lambda () '())))))))

(define merge$
  (lambda (S1$ S2$)
    (if (null? S1$)
	S2$
	(if (null? S2$)
	    S1$
	    (if (< (car S1$) (car S2$))
		(cons (car S1$) (lambda () (merge$ ((cdr S1$)) S2$)))
		(cons (car S2$) (lambda () (merge$ S1$ ((cdr S2$))))))))))

(define take$
  (lambda (S$ n)
    (if (or (= n 0) (null? S$))
	'()
	(cons (car S$) (take$ ((cdr S$)) (- n 1))))))

(define res1 (take$ (merge$ s1 s2) 100))

