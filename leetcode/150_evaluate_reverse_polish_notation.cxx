#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 計算後製表示式
 * 不知道難在哪裡
 */

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stack;

    for (string& s : tokens) {
      if (s != "+" && s != "-" && s != "*" && s != "/") {
        stack.push(stoi(s));
        continue;
      }

      int b = stack.top();
      stack.pop();
      int& a = stack.top();

      if (s == "+") {
        a += b;
      } else if (s == "-") {
        a -= b;
      } else if (s == "*") {
        a *= b;
      } else {
        a /= b;
      }
    }

    return stack.top();
  }
};