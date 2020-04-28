#include <algorithm>
#include <iostream>
#include <vector>

#include "./log.cxx"

using namespace std;

/**
 * 一定是前面小的換後面大的
 * 524321
 *  ^ ^
 * 開始下降的前一位 與後面最接近他的那位交換
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

    reverse(nums.begin() + i, nums.end());

    if (i == 0) return;

    int j = i;

    while (nums[j] <= nums[i - 1]) j++;

    swap(nums[i - 1], nums[j]);
  };
} solution;

int main() {
  vector<int> nums = {1, 3, 2};
  solution.nextPermutation(nums);

  log(nums);

  return 0;
}
