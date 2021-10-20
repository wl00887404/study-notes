
#include <iostream>
#include <stack>

using namespace std;

/**
 * 這題怎麼這麼多倒讚
 */

class Solution {
 public:
  string reverseWords(string s) {
    int size = s.size();
    stack<pair<int, int>> stack;

    int i = 0;
    while (i < size) {
      // 省略空白
      while (i < size && s[i] == ' ') i++;

      if (i == size) break;

      // 找到字串
      int j = i;
      while (j < size && s[j] != ' ') j++;
      stack.push({i, j});

      i = j;
    }

    string result = "";

    while (!stack.empty()) {
      pair<int, int> &pair = stack.top();
      for (int i = pair.first; i < pair.second; i++) {
        result += s[i];
      }
      stack.pop();

      if (!stack.empty()) result += ' ';
    }

    return result;
  }
};