
#include <iostream>
#include <vector>

using namespace std;

/**
 * 與 33 關聯
 */

/**
 * 不看 33 ，單純回想一下當初的作法
 * nums = [4, 5, 6, 6, 7, 0, 1, 2, 4, 4]
 *                        ^ pivot
 * 直接重複兩次觀察
 * 0 1 2 3 4 5 6 7 8 9  10 11 12 13 14 15 16 17 18 19
 * 4 5 6 6 7 0 1 2 4 4 | 4  5  6  6  7  0  1  2  4  4
 *           ^                       ^
 */

/**
 * 這題 hard 吧
 * 不看 33 根本想不起來 = =
 */

/**
 * 抄了 33 題發現在的會重複的問題在哪裡了
 * 假設 nums = [1, 1, 1, 2, 1, 1], target = 2
 * 想要用二分搜的話，要把 nums 判斷成 [1, 1, 1, 2, I, I]
 * 但是 1 在 2 前也有，如此沒辦法單靠數值去轉換 I
 */

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    for (int& num : nums) {
      if (num == target) return true;
    }

    return false;
  }
};

class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    size = nums.size();

    int pivot = findPivot(nums);
    int left = pivot;
    int right = pivot + size;

    while (left < right) {
      int mid = (left + right) / 2;
      int num = nums[mid % size];

      if (num == target) return true;
      if (num > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return false;
  }

  int size;
  int findPivot(vector<int>& nums) {
    if (nums[0] < nums[size - 1]) return 0;

    int left = 0;
    int right = size;

    while (true) {
      int mid = (left + right) / 2;

      if (mid > 0 && nums[mid] < nums[mid - 1]) return mid;

      if (nums[left] > nums[mid]) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
};