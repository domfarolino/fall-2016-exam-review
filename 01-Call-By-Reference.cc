/** call-by-reference

    address of (pointer to) the actual parameter is passed
    every time the parameter variable (not address) is accessed
    within the function the current value of the parameter is used
    when reading and new value stored when writing.
**/
#include <iostream>
using namespace std;

int i, j;
int array[10];

void secondPrintArray () {
   for (int i=0 ; i < 10 ; i++) cout << array[i] << " ";
   cout << "\n";
}

void initAndPrintArray(int x, int y, int a, int b) {
   for (int i = 0 ; i < 9 ; i++) {
     array[i] = i+1;
   }

   array[9] = 0;

   for (int i = 0 ; i < 9 ; i++) {
     if (i==x || i==y) cout << "* "; else cout << "  ";
   }

   cout << "    swap(";
   if (a == 0) cout << "i, "; else cout << "array[i], ";
   if (b == 0) cout << "j, array)"; else cout << "array[j], array)";
   cout << "\n";
   for (int i=0 ; i < 10 ; i++) cout << array[i] << " ";
   cout << "\n";
}

/* call by reference */
void swap (int x, int y, int arr[]) {
   int t = arr[x];
   arr[x] = arr[y];
   arr[y] = t;
}

int main() {
   i = 0;
   j = 1;
   initAndPrintArray(i,j,1,1);
   swap(array[i], array[j], array);
   secondPrintArray();
   cout << "-------------------\n";
   i = 1;
   j = 5;
   initAndPrintArray(i,j,1,1);
   swap(array[i], array[j], array);
   secondPrintArray();
   cout << "-------------------\n";
   i = 4;
   j = 5;
   initAndPrintArray(i,j,1,1);
   swap(array[i], array[j], array);
   secondPrintArray();
   cout << "-------------------\n";
   i = 4;
   j = 5;
   initAndPrintArray(i,j,0,0);
   swap(i, j, array);
   secondPrintArray();
   cout << "-------------------\n";
}
