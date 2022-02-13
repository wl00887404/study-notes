#include <iostream>

using namespace std;
/**
 *  題意：輾轉相除法要做幾次
 */

class Solution {
 public:
  int countOperations(int num1, int num2) {
    int result = 0;

    while (num1 != 0 && num2 != 0) {
      int& big = num1 > num2 ? num1 : num2;
      int& small = num1 > num2 ? num2 : num1;
      result += big / small;
      big %= small;
    }

    return result;
  }
};