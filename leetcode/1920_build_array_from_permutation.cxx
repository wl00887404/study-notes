#include <vector>
using namespace std;

/**
 * nums 是一個長度 n，0 ~ n - 1 的 array
 *
 * 重建一個 array 符合規則 ans[i] = nums[nums[i]]
 *
 * nums = [0, 2, 1, 5, 3, 4]
 *
 * ans[0] = nums[nums[0]] => nums[0] => 0
 * ans[1] = nums[nums[1]] => nums[2] => 1
 * ans[2] = nums[nums[2]] => nums[1] => 2
 */

/**
 * TODO: 思考一下怎麼讓空間複雜度是 O(1)
 *
 * nums = [0, 2, 1, 5, 3, 4]
 * ans = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
 *     = [0, 1, 2, 4, 5, 3]
 *
 * ans[1] 會用 nums[2] 覆蓋 nums[1]，可是 ans[2] 會用到 nums[1]
 * ans[3] 會用 nums[1] 覆蓋 nums[3]，可是 ans[4] 會用到 nums[3]
 *
 * ans[1]:
 *   temp  = nums[1] // 2
 *   nums[1] = nums[2]
 *
 * temp 要給用？
 *
 * nums[2] 用 ， nums[1] 存起來
 * 把 nums[2]
 */
class Solution {
 public:
  vector<int> buildArray(vector<int>& nums) {
    vector<int> ans(nums.size());

    for (int i = 0; i < nums.size(); i++) {
      ans[i] = nums[nums[i]];
    }

    return ans;
  }
};