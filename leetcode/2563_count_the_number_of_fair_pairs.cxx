#include <iostream>
#include <vector>

using namespace std;

/**
 * 找到陣列中兩個元素加起來 lower <= sum <= upper
 *
 * 排序後可以用「夾的」算數量？
 * nums = [0, 1, 4, 4, 5, 7], lower = 3, upper = 6
 * 0 => 找 3 <= num <= 6 => 4, 4, 5 => 3
 * 1 => 找 2 <= num <= 5 => 4, 4, 5 => 3
 * 4 => 找 -1 <= num <= 2 => 0, 1 => 2
 * 4 => 找 -1 <= num <= 2 => 0, 1 => 2
 * 5 => 找 -2 <= num <= 1 => 0, 1 => 2
 * 7 => 找 -4 <= num <= -1 => => 0
 *
 * 如果自己在範圍內
 */

class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());

    long long result = 0;
    int left = nums.size();
    int right = nums.size();

    for (int& num : nums) {
      while (0 < left && nums[left - 1] >= lower - num) {
        left--;
      }

      while (left < right && nums[right - 1] > upper - num) {
        right--;
      }

      result += right - left;
      if (lower <= num + num && num + num <= upper) {
        result--;
      }
    }

    return result / 2;
  }
};
