class Solution {
 public:
  long long sumAndMultiply(int n) {
    int a = 0;
    int b = 0;
    long long ia = 0;

    while (n != 0) {
      int c = n % 10;
      if (c != 0) {
        a = a * 10 + c;
        b += c;
      }

      n /= 10;
    }

    while (a != 0) {
      int c = a % 10;

      ia = ia * 10 + c;
      a /= 10;
    }

    return ia * b;
  }
};