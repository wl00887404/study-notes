class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;

    long long converted = 0;
    int copied = x;

    while (copied != 0) {
      converted *= 10;
      int ones = copied % 10;
      converted += ones;
      copied /= 10;
    }

    if (x == converted) return true;

    return false;
  }
};