#include <bits/stdc++.h>

#include <iostream>
#include <stack>
using namespace std;

/**
 * 欸不是
 * 要取最小耶
 * 那 getMin 要運作
 * pop() 就要更新值呀
 * 這樣怎麼會是 O(1)
 */

class MinStack {
 public:
  MinStack() {}

  void push(int val) {
    myStack.push(val);

    if (val < min) min = val;
  }

  void pop() {
    int top = myStack.top();
    myStack.pop();

    if (top != min) return;

    stack<int> stash;
    min = INT_MAX;

    while (!myStack.empty()) {
      if (myStack.top() < min) min = myStack.top();

      stash.push(myStack.top());
      myStack.pop();
    }

    while (!stash.empty()) {
      myStack.push(stash.top());
      stash.pop();
    }
  }

  int top() { return myStack.top(); }

  int getMin() { return min; }

 private:
  stack<int> myStack;
  int min = INT_MAX;
};
