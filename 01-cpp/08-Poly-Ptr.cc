#include <stdlib.h>
#include <iostream>

using namespace std;

/**
  - rationale: passing parameters through void* pointers has many applications,
       not just to threads.  This example sorts an array of Cable struct
       objects by increasing cost.  It uses the builtin 'qsort' function.
       That function takes four parameters: a pointer to the array being sorted,
       the number of elements in the array, the size in bytes of each element
       (so qsort can identify the location of the ith element of the array),
       and a pointer to a 'compare' function of two arguments that is user
       defined and outputs -1/+1/0 if the left argument points to an array
       entry that is considered 'less than'/'greater than'/'equal to' the
       element pointed to by the right argument, respectively.
  - note: in C/C++ the name of a function is a pointer to the function.
       the signature of 'qsort' is this (from 'man qsort' in unix):
          void qsort(void *base, size_t nmemb, size_t size,
                     int (*compar)(const void *, const void *));
       the fourth argument declares 'compar' to be a pointer to a function
       taking two void* pointers as input and returns an int value (-1/+1/0).
       The type 'size_t' is just an unsigned long int.
**/

class Cable {
public:
   int city1, city2, cost;
};

/* This is the user-defined cost compare function for qsort's 4th argument */
/* a cable with less cost moves toward the front of the array              */
/* (that is, qsort swaps it with the cable of higher cost, if necessary)   */
/* since array elements are pointers, x and y need to be dereferenced      */
/* twice to access the actual Cable objects to be sorted                   */
int costCompare (const void* x, const void* y) {
   if ((**((Cable**)x)).cost < ((**(Cable**)y)).cost) return -1;
   if ((**((Cable**)x)).cost > ((**(Cable**)y)).cost) return 1;
   return 0;
}

int main() {
   int i;
   Cable* cables[10];   /* an array of 10 pointers to Cable objects        */

   for (i=0 ; i < 10 ; i++) {   /* array elements are assigned values      */
      cables[i] = (Cable*)new Cable();
      (*cables[i]).city1 = i;
      (*cables[i]).city2 = i+1;
      (*cables[i]).cost = rand() % 200;  /* costs are assigned randomly    */
   }

   /* Sort a list of cables on increasing cost                             */
   /* Builtin function 'sizeof' returns the # bytes of memory the type,    */
   /* stated as its argument, actually takes up.                           */
   qsort(cables, 10, sizeof(Cable*), costCompare);

   /* Print the sorted array
      (operator -> is used because elements are pointers to objects        */
   for (i=0 ; i < 10 ; i++)
      cout << "[" << (*cables[i]).city1 << "," << (*cables[i]).city2 << ","
	   << (*cables[i]).cost << "]\n";

   return 0;
}
