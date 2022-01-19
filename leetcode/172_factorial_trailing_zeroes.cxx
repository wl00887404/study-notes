#include <iostream>

using namespace std;

/**
 * 要產生結尾 0
 * 就一定要有 2 * 5 嘛
 * 2 太長出現了
 * 只要考慮 5 就好
 *
 * 1 2 3 4 5
 *   ^     ^
 * n = 5 就有一個 0
 *
 * n = 25 會有 5 + 1 個
 * 分別是
 * 5 10 15 20 25
 * 5  5  5  5  5 除第一次 5
 *             5 除第二次 5
 * 
 * 就是一直除 5 就有所有答案了
 */

class Solution {
 public:
  int trailingZeroes(int n) {
    int result = 0;

    while (n != 0) {
      n /= 5;
      result += n;
    }

    return result;
  }
};