#include <iostream>
#include <stack>

using namespace std;

/**
 * 題意︰移除最少的字元，讓左刮號與右刮號合法
 *
 * 由左掃到右
 * 紀錄可用左括號數量
 * 如果遇到右括號，左括號數量 -1
 * 左括號數量不夠的話，就移除有右括號
 */

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    int size = s.size();

    stack<int> leftParenthesisIndexes;
    bool isSkip[size];

    for (int i = 0; i < size; i++) {
      isSkip[i] = false;
      if (s[i] != '(' && s[i] != ')') continue;

      if (s[i] == '(') {
        leftParenthesisIndexes.push(i);
        continue;
      }

      if (leftParenthesisIndexes.empty()) {
        // 當 ) 沒有 ( 可以用了
        isSkip[i] = true;
        continue;
      }

      // ( ) 左右匹配
      leftParenthesisIndexes.pop();
    }

    while (!leftParenthesisIndexes.empty()) {
      // 沒有用到的左括號
      isSkip[leftParenthesisIndexes.top()] = true;
      leftParenthesisIndexes.pop();
    }

    string result = "";

    for (int i = 0; i < size; i++) {
      if (isSkip[i]) continue;

      result += s[i];
    }

    return result;
  }
};