#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

/**
 * 老樣子
 * 連續序列加總可以逆推
 * [0, 0] [0, 1] [0, 2] [0, 3] [0, 4] [0, 5]
 *
 * [1, 1] = [0, 1] / [0, 0]
 *
 * 0 怎麼辦？斷開魂結嗎？
 */

class Solution {
 public:
  int maxProduct(vector<int>& nums) { return maxProduct(nums, 0); }
  double maxProduct(vector<int>& nums, int i) {
    int min = 1;
    double product = 1;
    double result = -INFINITY;

    for (; i < nums.size(); i++) {
      if (nums[i] == 0) {
        return max(max(maxProduct(nums, i + 1), result), 0.0);
      };

      product *= nums[i];
      result = max(max(result, product), product / min);
      /**
       * input:   [2,  -5, -2,  -4,    3]
       * product: [2, -10, 20, -80, -240]
       * 最佳解釋 -240 / -10
       * min 要取負的而且絕對值小的
       */
      if (0 > product && (min == 1 || product > min)) min = product;
    }

    return result;
  }

} solution;

int main() {
  vector<int> nums = {-3, -1, -1};

  solution.maxProduct(nums);

  return 0;
}