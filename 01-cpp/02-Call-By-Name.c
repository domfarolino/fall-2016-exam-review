/** call-by-name

    a function that computes the value of the actual parameter is passed

    arguments to functions are evaluated at the last possible moment, just
    before they're needed

    Example:

    declare array[], i, j    call swap(array[i],array[j])

    swap(x, y) {            becomes    swap(array[i],array[j]) {
       t = array[x];                      t = array[array[i]];
       array[x] = array[y];               array[array[i]] = array[array[j]];
       array[y] = t;                      array[array[j]] = t;
    }                                  }
**/

#include <stdio.h>

int A[] = { 1,2,3,4,5,6,7,8 };
int i, j;

/* for computing A[i] */
int fi () {
   printf("in fi: i=%d, A[i]=%d, A[A[i]]=%d\n",i,A[i],A[A[i]]);
   return A[i];
}

/* for computing i=A[i] */
int fj () {
   printf("in fj: i=%d:\n",i);
   i = A[i];
   printf("i=%d, A[i]=%d, A[A[i]]=%d\n",i,A[i],A[A[i]]);
   return i;
}

int swap (int(*f)(), int(*g)()) {
   int temp = A[f()];
   printf("temp=%d\n",temp);
   printf("-------------\n");
   A[f()] = A[g()];
   printf("-------------\n");
   printf("temp=%d\n",temp);
   A[g()] = temp;
}

int main () {
   int k;
   i = 3;

   // fi = 4
   // fj = 3

   /* A[A[3]] = A[4] = 5; A[i=A[3]] = A[4] = 5 */
   /* no change if call-by-value, if call-by-name */
   /* temp = A[f()] = A[A[A[3]]] = A[5] = 6 */
   /* since g() is evaluated before f(): */
   /* A[f()] = A[A[A[4]]] = A[6] = A[g()] = A[5] = 6 */
   /* A[g()] = */
   /* 1,2,3,4,5,6,7,8 -> 1,2,3,4,5,7,6,8
   /* swap (A[A[i]], A[i=A[i]]) */

   swap (fi,fj);
   for (k=0 ; k < 8 ; k++) { printf("%d ",A[k]); }
   printf("\ni=%d\n",i);
}
