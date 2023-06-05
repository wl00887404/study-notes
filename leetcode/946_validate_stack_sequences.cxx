#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 還原來這題我在 2022 年寫過
 */

class Solution2022 {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int i = 0;
    int j = 0;
    int size = pushed.size();

    while (i < size && j < size) {
      if (0 <= i && pushed[i] == popped[j]) {
        j++;

        pushed[i] = -1;  // 改成負值以刪掉數字

        while (0 <= i && pushed[i] < 0) i--;
      } else {
        i++;
      }
    }

    return i == -1 && j == size;
  }
};

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int size = pushed.size();
    unordered_set<int> isShown;
    stack<int> s;

    int i = 0;
    int j = 0;

    while (i < size && j < size) {
      // push 直到遇到要 pop 的元素
      while (i < size && !isShown.count(popped[j])) {
        s.push(pushed[i]);
        isShown.insert(pushed[i]);
        i++;
      }

      while (j < size && !s.empty()) {
        // 如果不一樣，那就不用繼續 pop 了
        if (s.top() != popped[j]) {
          // 不只不一樣，目標要 pop 的元素還深埋在 stack 中
          if (isShown.count(popped[j])) return false;
          break;
        }
        s.pop();
        j++;
      }
    }

    return s.empty() && j == size;
  }
};