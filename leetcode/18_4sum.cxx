
#include <algorithm>
#include <iostream>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 *  0  1 2 3 4 5
 * -2 -1 0 0 1 2
 *  ^  ^ ^     ^    sum = -1
 * -2 -1 0 0 1 2
 *  ^  ^     ^ ^    sum =  0 | this!
 * -2 -1 0 0 1 2
 *  ^    ^ ^   ^    sum =  0 | this!!
 * -2 -1 0 0 1 2
 *     ^ ^ ^   ^    sum =  1
 * -2 -1 0 0 1 2
 *     ^ ^ ^ ^      sum =  0 | this!!!
 * -2 -1 0 0 1 2
 *       ^ ^ ^ ^             | l > target
 */

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int length = nums.size();
    vector<vector<int>> results;

    sort(nums.begin(), nums.end());

    if (length < 4) return results;

    /**
     * ll: left left
     * l: l
     * r: right
     * rr: right right
     */
    for (int ll = 0; ll < length - 3; ll++) {
      if (ll > 0 && nums[ll] == nums[ll - 1]) continue;

      // 最小會 target 大
      if (nums[ll] + nums[ll + 1] + nums[ll + 2] + nums[ll + 3] > target) break;

      // 最大會比 target 大
      if (nums[ll] + nums[length - 3] + nums[length - 2] + nums[length - 1] <
          target) {
        continue;
      }

      for (int l = ll + 1; l < length - 2; l++) {
        if (l > ll + 1 && nums[l] == nums[l - 1]) continue;

        // 最小會 target 大
        if (nums[ll] + nums[l] + nums[l + 1] + nums[l + 2] > target) break;

        // 最大會比 target 大
        if (nums[ll] + nums[l] + nums[length - 2] + nums[length - 1] < target) {
          continue;
        }

        int r = l + 1;
        int rr = length - 1;

        while (r < rr) {
          int sum = nums[ll] + nums[l] + nums[r] + nums[rr];

          if (sum == target) {
            results.push_back({nums[ll], nums[l], nums[r], nums[rr]});
          }

          if (sum <= target) {
            while (r < rr && nums[r] == nums[r + 1]) r++;

            r++;
          }

          if (sum >= target) {
            while (r < rr && nums[rr - 1] == nums[rr]) rr--;

            rr--;
          }
        }
      }
    }

    return results;
  }
} solution;

int main() {
  // vector<int> nums = {1, 0, -1, 0, -2, 2};
  // vector<int> nums = {0, 0, 0, 0};
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> results = solution.fourSum(nums, -1);

  log(results);

  return 0;
}