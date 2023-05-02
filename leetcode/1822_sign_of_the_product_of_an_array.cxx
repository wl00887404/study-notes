#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int sign = 1;

    for (int& num : nums) {
      if (num == 0) return 0;

      if (num < 0) sign *= -1;
    }

    return sign;
  }
};