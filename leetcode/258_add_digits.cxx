class Solution {
 public:
  int addDigits(int num) {
    while (num >= 10) {
      int nextNum = 0;

      do {
        nextNum += num % 10;
      } while (num /= 10);

      num = nextNum;
    }

    return num;
  }
};

/**
 * 挑戰一下 O(1)
 * 原本數字假設是 a * 10 ** 2 + b * 10 ** 1 + c * 10 ** 0
 * 數字和是 a + b + c
 * a * 10 ** 2 + b * 10 ** 1 + c * 10 ** 0 (mod 9)
 * = a * (1 + 9) ** 2 + b * (1 + 9) + c (mod 9)
 * = a * 1 + b * 1 + c * 1
 *
 * 所以 mod 9 的結果就是數字和
 */

class ModSolution {
 public:
  int addDigits(int num) {
    if(num == 0) return 0;
    int result = num % 9;

    return result == 0 ? 9 : result;
  }
};