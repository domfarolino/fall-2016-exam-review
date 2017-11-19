(define findmax-1
  (lambda (lst) 
    (if (null? lst)
	'()
	(if (null? (cdr lst))
	    (car lst)
	    (max (car lst) (findmax-1 (cdr lst)))))))

(define res1 (findmax-1 '(2 3 4 5 6 7 6 5 3 4 2 1 9 7 7 2 2)))

(define findmax-2
  (lambda (lst acc) 
    (if (null? lst)
	acc
	(if (null? (cdr lst))
	    (max (car lst) acc)
	    (findmax-2 (cdr lst) (max (car lst) acc))))))

(define res2 (findmax-2 '(2 3 4 5 6 7 6 5 3 4 2 1 9 7 7 2 2) 2))

(define findmax-3
  (lambda (lst)
    (letrec ((f (lambda (l acc)
		  (if (null? l)
		      acc
		      (if (null? (cdr l))
			  (max (car l) acc)
			  (f (cdr l) (max (car l) acc)))))))
      (f lst (car lst)))))

(define res3 (findmax-3 '(2 3 4 5 6 7 6 5 3 4 2 1 9 7 7 2 2)))
