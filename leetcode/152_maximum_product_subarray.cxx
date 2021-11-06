#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

/**
 * 老樣子
 * subarray 可以 O(n) 去推算
 * 不需要到 O(n ^ 2)
 * [0, 0] [0, 1] [0, 2] [0, 3] [0, 4] [0, 5]
 *
 * [1, 1] = [0, 1] / [0, 0]
 * [1, 2] = [0, 2] / [0, 0]
 * [2, 2] = [0, 2] / [0, 1]
 */

class Solution {
 public:
  int maxProduct(vector<int>& nums) { return maxProduct(nums, 0); }
  double maxProduct(vector<int>& nums, int i) {
    // 如果第一次遇到負數
    // 沒有前面其他的負數可以除
    // 那就等同於除以 1
    int maxNegativeProduct = 1; 
    double product = 1;
    double result = -INFINITY;

    for (; i < nums.size(); i++) {
      // 0 會中斷連續乘積
      // 遇到 0 的話
      // 結果必為 0 之前、 0 、 0 之後
      if (nums[i] == 0) {
        return max(max(result, maxProduct(nums, i + 1)), 0.0);
      };

      product *= nums[i];
      if (product > 0) {
        // 因為沒有小數，所以後面乘積一定比前面大
        result = product;
      } else {
        /**
         * input:   [2,  -5, -2,  -4,    3]
         * product: [2, -10, 20, -80, -240]
         * 最佳解是 -240 / -10
         * maxNegativeProduct 要取負的而且絕對值小的
         */
        result = max(result, product / maxNegativeProduct);
        if (maxNegativeProduct == 1 || product > maxNegativeProduct) {
          maxNegativeProduct = product;
        }
      }
    }

    return result;
  }
} solution;

int main() {
  vector<int> nums = {-3, -1, -1};

  solution.maxProduct(nums);

  return 0;
}