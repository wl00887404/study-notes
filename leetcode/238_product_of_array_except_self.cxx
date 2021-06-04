#include <iostream>
#include <vector>

using namespace std;

/**
 * [ 2,  3,  4,  5]
 * [60, 40, 30, 24]
 * [1, 2]
 *
 * result[i] = result[i - 1] * nums[i - 1]
 *           = result[i + 1] * nums[i + 1]
 *
 * if n = 9
 * r[0] = n[1 ... 10]
 * r[1] = n[0] * n[2 ... 10]
 * r[8] = n[0 ... 7] * n[9]
 * r[9] = n[0 ... 8]
 *
 * 一個從前面來
 * 一個從後面回
 */

class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int length = nums.size();
    int product = 1;
    vector<int> result(length);
    result[0] = 1;

    for (int i = 1; i < length; i++) {
      product *= nums[i - 1];
      result[i] = product;
    }

    product = 1;
    for (int i = length - 2; 0 <= i; i--) {
      product *= nums[i + 1];
      result[i] *= product;
    }

    return result;
  }
};
