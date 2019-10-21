#include <iostream>
using namespace std;

int foo;
int *pointer = nullptr;
int array[] = {38, 16, 54};

const int *const_pointer1 = &foo;  // 不能改變數值的 pointer
int *const const_pointer2 = &foo;  // 不能改變位址的 pointer

void print() {
  cout << "foo: " << foo << endl;
  cout << "&foo: " << &foo << endl;
  cout << "pointer: " << pointer << endl;
  cout << "&pointer: " << &pointer << endl;
  cout << "*pointer: " << *pointer << endl;
}

int main() {
  foo = array[0];
  pointer = &foo;
  print();
  cout << "---" << endl;

  foo = array[1];
  print();
  cout << "---" << endl;

  *pointer = array[2];
  print();

  return 0;
}
