
#include <algorithm>
#include <iostream>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * 3sum 的延伸
 */

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int length = nums.size();
    int result;

    sort(nums.begin(), nums.end());

    for (int left = 0; left < length - 2; left++) {
      int mid = left + 1;
      int right = length - 1;

      while (mid < right) {
        int sum = nums[left] + nums[mid] + nums[right];

        if (sum == target) return target;

        if ((left == 0 && mid == left + 1 && right == length - 1) ||
            abs(sum - target) < abs(result - target)) {
          result = sum;
        }

        if (sum < target) {
          while (mid < right && nums[mid] == nums[mid + 1]) mid++;

          mid++;
        } else {
          // == 在 L28
          while (mid < right && nums[right - 1] == nums[right]) right--;

          right--;
        }
      }
    }

    return result;
  }
} solution;

int main() {
  vector<int> nums = {-1, 2, 1, -4};

  cout << solution.threeSumClosest(nums, 1) << endl;

  return 0;
}