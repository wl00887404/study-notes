#include <iostream>
#include <queue>
using namespace std;

/**
 * 跟 322 的 coin change 一樣
 */

class Solution {
 public:
  int numSquares(int n) {
    int result = 0;
    bool isUsed[n + 1];
    for (int i = 0; i <= n; i++) isUsed[i] = false;
    queue<int> queue;
    queue.push(0);

    while (true) {
      result++;
      int length = queue.size();
      while (length--) {
        int& value = queue.front();
        int i = 1;

        while (true) {
          int nextValue = value + i * i;

          if (nextValue == n) return result;
          if (nextValue > n) break;
          if (isUsed[nextValue]) break;

          isUsed[i] = true;
          queue.push(nextValue);
          i++;
        }

        queue.pop();
      }
    }

    // 這行應該不會被執行到
    // 因為 1 + 1 + 1 最後一定會加到
    return 0;
  }
};