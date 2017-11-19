/**
    type-unsafe-2.c

    Type safety:
    No undesirable program behavior that is caused by a discrepancy
    between differing data types for constants, variables, and functions
    Types could be primitive or manufactured (structs, classes)
**/
#include <string.h>
#include <stdio.h>

typedef struct { char arr[100]; } S1;
typedef struct { char arr[10]; } S2;

int main() {
  int i;
  /* reverse the order of the next two lines to reverse the order in
    which the data for these variables occurs on the stack */

  S2 b;
  S1 a;

  strncpy(a.arr, "Joe is my best friend and he is from Sandusky\0", 36);
  strncpy(b.arr, "Pete\0", 5);

  printf("b.arr (before) = %s\n", b.arr);
  printf("a.arr (before) = %s\n", a.arr);

  memcpy(b.arr, a.arr, 36);

  printf("b.arr (after)  = %s\n", b.arr);
  printf("a.arr (after)  = %s\n", a.arr);
}
