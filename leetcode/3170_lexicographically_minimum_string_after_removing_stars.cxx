#include <iostream>
#include <vector>

using namespace std;

/**
 * 字串裡有星星
 * 可以刪除星星，當刪除一個星星時，必須刪除星星左側的最小字元
 */

class Solution {
 public:
  string clearStars(string s) {
    int size = s.size();
    int nextSize = size;
    vector<stack<int>> stacks(26);
    vector<bool> remains(size, true);
    int minCIndex = 26;  // 目前最小的字元

    for (int i = 0; i < size; i++) {
      int cIndex = s[i] - 'a';
      if (s[i] != '*') {
        minCIndex = min(minCIndex, cIndex);
        stacks[cIndex].push(i);
        continue;
      }

      nextSize -= 2;
      remains[i] = false;
      remains[stacks[minCIndex].top()] = false;
      stacks[minCIndex].pop();

      // 如果目前最小的字元已經用光光了
      while (minCIndex < 26 && stacks[minCIndex].empty()) {
        minCIndex++;
      }
    }

    char result[nextSize + 1];
    int i = 0;
    result[nextSize] = '\0';
    for (int j = 0; j < s.size(); j++) {
      if (remains[j] != true) continue;
      result[i] = s[j];
      i++;
    }

    return string(result);
  }
};