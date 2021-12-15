#include <iostream>
#include <stack>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    int size = path.size();
    stack<pair<int, int>> stack;

    for (int i = 1; i < size; i++) {
      int from = i;
      int to = from;
      while (to < size && path[to] != '/') to++;

      if (to - from == 0) {
        // 沒字串什麼也不做
      } else if (to - from == 1 && path[from] == '.') {
        // . 也什麼都不做
      } else if (to - from == 2 && path[from] == '.' && path[from + 1] == '.') {
        // .. 移除上一個路徑
        if (!stack.empty()) stack.pop();
      } else {
        stack.push({from, to});
      }

      i = to;
    }

    if (stack.empty()) return "/";

    string result = "";

    while (!stack.empty()) {
      result = "/" +
               path.substr(stack.top().first,
                           stack.top().second - stack.top().first) +
               result;
      stack.pop();
    }

    return result;
  }
};