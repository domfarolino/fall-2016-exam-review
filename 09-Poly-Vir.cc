/* Virtual functions */
#include <iostream>
#include <string.h>
using namespace std;

class top {
private:
   void *object;

public:
   void setObject (void *obj) { object = obj; }
   void *getObject() { return object; }
   virtual void show () { cout << "No way Jose "; }
};

class A : public top {
public:
   A (int *number) { setObject(number); }
   void show () { cout << *(int*)getObject() << " "; }
};

class B : public top {
public:
   B (const char *str) { setObject((void*)str); }
   void show () { cout << (char*)getObject() << " "; }
};

class Node {
public:
   Node *next;
   top *object;
   Node (Node *nxt, top *obj) { next = nxt; object = obj; }
};

class List {
   Node *head = NULL;
public:
   void insert (top *obj) {  head = new Node(head, obj); }

   void show () {
      Node *ptr = head;
      while (ptr != NULL) { 
	 ptr->object->show();
	 ptr = ptr->next; 
      }
      cout << "\n";
   }
};

int main () {
   List list;
   list.insert(new B("one"));
   list.insert(new A(new int(2)));
   list.insert(new A(new int(3)));
   list.insert(new B("four"));
   list.insert(new A(new int(5)));
   list.show();
}
