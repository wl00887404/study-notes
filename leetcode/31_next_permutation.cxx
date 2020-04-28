#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 一定是前面小的換後面大的
 * 132 1432
 *  ^   ^
 * 開始下降的前一位 與後面最接近他的那位交換
 * 然後 sort 後面
 *
 * 竟然有 next_permutation 的內建函數
 * 好扯喔
 */

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int length = nums.size();
    int i = length - 1;

    while (0 < i && nums[i - 1] >= nums[i]) i--;

    if (i != 0) {
      int closest = i;

      for (int j = 0; j < length - i; j++) {
        if (nums[i + j] <= nums[i - 1]) continue;

        int diff = nums[i + j] - nums[i - 1];

        if (diff < nums[closest] - nums[i - 1]) closest = i + j;
        if (diff == 1) break;
      }
      swap(nums[i - 1], nums[closest]);
    };

    sort(nums.begin() + i, nums.end());
  }
};