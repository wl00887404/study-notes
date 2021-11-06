#include <iostream>
#include <vector>

using namespace std;

/**
 * 完全沒有想到 xor
 */

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int result = 0;

    for (int& num : nums) result ^= num;

    return result;
  }
};