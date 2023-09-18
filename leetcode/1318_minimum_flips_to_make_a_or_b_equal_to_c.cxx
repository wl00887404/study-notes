#include <iostream>

using namespace std;


/**
 * 目標是讓 a | b == c
 * 如果某個 bit ， c 是 0 ，那 a 跟 b 一定要是 0
 * 如果 c 是 1 ，那 a 跟 b 其中一個是 1 就好，不能都是 0
 */

class Solution {
 public:
  int minFlips(int a, int b, int c) {
    int result = 0;

    while (a != 0 || b != 0 || c != 0) {
      int aBit = a & 1;
      int bBit = b & 1;
      int cBit = c & 1;

      if (cBit == 0) {
        if (aBit != 0) result++;
        if (bBit != 0) result++;
      } else {
        if (aBit != 1 && bBit != 1) result++;
      }

      a = a >> 1;
      b = b >> 1;
      c = c >> 1;
    }

    return result;
  }
};