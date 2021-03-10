#include <iostream>
using namespace std;

struct Dog {
  string name;
  int age;
  Dog() : name("unnamed"), age(0) {}
};

int main() {
  Dog cappuccino;
  cappuccino.name = "cappuccino";
  cappuccino.age = 5;

  Dog *pointer = &cappuccino;

  cout << (*pointer).name << endl;
  cout << pointer->age << endl;

  return 0;
}