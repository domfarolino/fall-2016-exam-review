# fall-2016-exam-review

Franco's programming languages exam review that I gave.

C++/Java
--------
  memory safety:
  --------------
    unsafe-1.cc
    unsafe-2.cc

  type safety:
  ------------
    typ_unsafe_1.java (Casting even with Generics)
    typ_safe_1.java   (Generics)
    typ-unsafe-1.c
    typ-unsafe-2.c


  thread safety:
  --------------
    thread_safe.java - locks: can guarantee serializeable, deadlock-free code

  polymorphism:
  -------------
    C/C++:  (pointers to functions, virtual functions, also STL)
    ------
      poly-ptr.cc
      poly-vir.cc

  parameter passing:
  ------------------
    call-by-name.c
    call-by-ref.cc
    call-by-val.cc

Scheme
------
  tail recursion:
  ---------------
    tail.ss

  Continuation passing style (streams):
  -------------------------------------
    cps.ss

  Call-with-current-continuation:
  -------------------------------
    call-cc.ss

  Closure:
  --------
    closure.ss
