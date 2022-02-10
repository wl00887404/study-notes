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