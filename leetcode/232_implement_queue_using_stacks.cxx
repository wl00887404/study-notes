#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
 private:
  stack<int> s1;
  stack<int> s2;
  void toS2() {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }

  void toS1() {
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }

 public:
  MyQueue() {}

  void push(int x) {
    toS1();
    s1.push(x);
  }

  int pop() {
    toS2();
    int result = s2.top();
    s2.pop();
    return result;
  }

  int peek() {
    toS2();
    return s2.top();
  }

  bool empty() { return s1.empty() && s2.empty(); }
};