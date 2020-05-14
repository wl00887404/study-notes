class Solution {
 public:
  bool isPerfectSquare(int num) {
    if (num == 1) return true;

    long long i = 2;
    while (true) {
      long long pow2 = i * i;

      if (pow2 > num) return i - 1;

      i++;
    }
  }
};