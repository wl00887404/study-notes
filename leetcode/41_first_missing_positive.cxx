#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 排序不可能 = =
 * 正解是做一個 O(n) 的假排序
 * 0 2 6 5 3 4 1
 */

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int length = nums.size();

    if (length == 0) return 1;

    if (length == 1) return nums[0] == 1 ? 2 : 1;

    // sort(nums.begin(), nums.end());

    for (int i = 0; i < length; i++) {
      /**
       * 5 3 4 2 4 -1
       *
       * nums[4] 是 4 不是 5
       * 4 3 4 2 5 -1
       *
       * nums[3] 是 2 不是 4
       * 2 3 4 4 5 -1
       *
       * nums[1] 是 3 不是 2
       * 3 2 4 4 5 -1
       *
       * nums[2] 是 4 不是 3
       * 4 2 3 4 5 -1
       */

      while (length >= nums[i] && nums[i] > 0 && nums[nums[i] - 1] != nums[i]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 1; i <= length; i++) {
      if (nums[i - 1] != i) return i;
    }

    return length + 1;
  }
} solution;

int main() {
  vector<int> nums = {3, 4, -1, 1};

  cout << solution.firstMissingPositive(nums) << endl;

  return 0;
}