class Solution {
 public:
  int mySqrt(int x) {
    long long i = 0;
    while (true) {
      long long pow2 = i * i;

      if (pow2 > x) return i - 1;

      i++;
    }
  }
};