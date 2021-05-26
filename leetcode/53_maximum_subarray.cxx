#include <iostream>
#include <vector>
using namespace std;

/**
 * [5, 4, -1, 7, 8] 總共 5 個
 * [0, 0] [0, 1] [0, 2] [0, 3] [0, 4]
 *        [1, 1] [1, 2] [1, 3] [1, 4]
 *               [2, 2] [2, 3] [2, 4]
 *                      [3, 3] [3, 4]
 *                             [4, 4]
 * 其中
 *   [1, 1] = [0, 1] - [0, 0]
 *   [1, 2] = [0, 2] - [0, 0]
 *   [1, 3] = [0, 3] - [0, 0]
 *   [1, 4] = [0, 4] - [0, 0]
 */

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int length = nums.size();
    int sum = 0;
    int min = 0;
    int result;

    for (int i = 0; i < length; i++) {
      sum += nums[i];

      if (i == 0 || sum > result) result = sum;
      if (sum - min > result) result = sum - min;
      if (sum < min) min = sum;
    }

    return result;
  }
} solution;

int main() {
  vector<int> nums = {-2, -1};

  solution.maxSubArray(nums);

  return 0;
}