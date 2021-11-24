#include <iostream>
#include <vector>

using namespace std;

/**
 * 一個已排序的陣列
 * 只有一個元素會出現一次
 * 其他都是兩次
 *
 * Binary Search 的想法
 * 中間剖一半
 *
 * 1 2 2 3 3
 * 1 1 2 3 3
 * 1 1 2 2 3
 *
 * 目標在左邊 => 一樣的數字會在左邊
 * 目標在右邊 => 一樣的數字會在右邊
 *
 * 1 2 2 3 3 4 4
 * 1 1 2 3 3 4 4
 * 1 1 2 2 3 4 4
 * 1 1 2 2 3 3 4
 *
 * 目標在左邊 => 一樣的數字在右邊
 * 目標在右邊 => 一樣的數字在左邊
 */

class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return nums[0];

    int left = 0;
    int right = size;

    while (left < right) {
      int mid = (left + right) / 2;

      if (mid + 1 < size && nums[mid] == nums[mid + 1]) {
        if (mid % 2) {
          right = mid;
        } else {
          left = mid + 1;
        }
      } else if (0 <= mid - 1 && nums[mid - 1] == nums[mid]) {
        if (mid % 2) {
          left = mid + 1;
        } else {
          right = mid;
        }
      } else {
        return nums[mid];
      }
    }

    return nums[left];
  }
};