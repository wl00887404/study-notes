/**
 * 每日 easy
 * 太簡單了不知道有什麼好說的
 */

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n < 1) return false;
    if (n == 1) return true;

    while (n != 1) {
      if (n % 2 == 1) return false;

      n /= 2;
    }

    return true;
  }
};