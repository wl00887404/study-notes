
/**
 * 這題跟 1009 一樣
 * 只是測試集沒有 0
 * 所以不需要對 0 做特別處理
 */

class Solution {
 public:
  int findComplement(int num) {
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