#include <bitset>
#include <iostream>
using namespace std;

/**
 * 原來是要左右顛倒！
 */

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    int i = 31;

    while (i--) {
      result |= n & 1;
      n >>= 1;
      result <<= 1;
    }

    result |= n & 1;

    return result;
  }
} solution;

int main() {
  solution.reverseBits(43261596);  // 00000010100101000001111010011100
  return 0;
}
