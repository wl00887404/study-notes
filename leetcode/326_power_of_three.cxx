#include <iostream>

using namespace std;

/**
 * follow up 說可不可能不要用迴圈或遞迴解
 * 等等太難了吧
 * 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323,
 * 4782969
 */

class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n <= 0) return 0;

    while (n != 1) {
      if (n % 3) return false;

      n /= 3;
    }

    return 1;
  }
};

/**
 * 看解答的
 * 太神了吧
 *
 * https://leetcode.com/problems/power-of-three/discuss/77856/1-line-java-solution-without-loop-recursion
 */

class OnelineSolution {
 public:
  bool isPowerOfThree(int n) { return (n > 0 && 1162261467 % n == 0); }
};
