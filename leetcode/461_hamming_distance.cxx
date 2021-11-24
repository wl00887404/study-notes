class Solution {
 public:
  int hammingDistance(int x, int y) {
    int xXorY = x ^ y;
    int result = 0;
    while (xXorY) {
      if ((xXorY & 1) != 0) result++;

      xXorY >>= 1;
    }

    return result;
  }
};