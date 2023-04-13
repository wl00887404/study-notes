#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
  string removeStars(string s) {
    stack<char> stack;

    int starCount = 0;
    for (const char& c : s) {
      if (c != '*') {
        stack.push(c);
        continue;
      }

      stack.pop();
    }

    int size = stack.size();

    if (size == s.length()) return s;

    char result[size + 1];
    int& last = size;
    result[last] = '\0';
    last--;

    while (!stack.empty()) {
      result[last] = stack.top();
      last--;
      stack.pop();
    }

    return string(result);
  }
};