/**
 * 第一輪是 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28
 * 第二輪是 2 + ... + 8 = 35
 */

class Solution {
 public:
  int totalMoney(int n) {
    int round = n / 7;
    int result = (4 + 4 + round - 1) * round / 2 * 7;

    int& begin = round;
    for (int j = n % 7; j > 0; j--) {
      begin++;
      result += begin;
    }

    return result;
  }
};