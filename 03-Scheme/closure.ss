(define f (lambda (op) (lambda (x y) (op x y))))
(define x (f +))
(define res1 (x 3 4))
(define x (f cons))
(define res2 (x 'a '(b c)))

(define stack-maker
  (lambda (s)
    (lambda msg
      (case (car msg)
	('peek (if (null? s) '() (car s)))
	('push (stack-maker (cons (cadr msg) s)))
	('pop  (stack-maker (cdr s)))
	('show (show-stuff s))
	(else s)))))

(define person-maker
  (lambda (name)
    (lambda msg
      (case (car msg)
	('name name)
	(else (error 'yikes))))))

(define criminal
  (lambda (name years)
    (let ((p (person-maker name)))
      (lambda msg
	(case (car msg)
	  ('years years)
	  ('show (list name years))
	  (else (apply p msg)))))))

(define show-stuff
  (lambda (s)
    (if (null? s)
	'()
	(cons ((car s) 'show) (show-stuff (cdr s))))))

(define res3
  (let* ((crimeS (stack-maker '()))
	 (crimeS (crimeS 'push (criminal 'Lisa 23)))
	 (crimeS (crimeS 'push (criminal 'Louise 11)))
	 (crimeS (crimeS 'push (criminal 'Larry 8)))
	 (crimeS (crimeS 'push (criminal 'Lawrence 12)))
	 (a1 (crimeS 'show))
	 (crimeS (crimeS 'pop))
	 (a2 (crimeS 'show))
	 (crimeS (crimeS 'push (criminal 'Jim 1)))
	 (a3 (crimeS 'show)))
    (list a1 "||" a2 "||" a3)))
    
