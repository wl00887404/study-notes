/**
 * 與 476 同一題
 * 只是要對 0 做特別處理
 */

class Solution {
 public:
  int bitwiseComplement(int num) {
    if (num == 0) return 1;

    int result = 0;
    int i = 0;

    while (num) {
      if ((num & 1) == 0) {
        result |= (1 << i);
      }

      i++;
      num >>= 1;
    }

    return result;
  }
};