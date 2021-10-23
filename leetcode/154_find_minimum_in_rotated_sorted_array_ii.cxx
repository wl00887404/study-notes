#include <iostream>
#include <vector>

using namespace std;

/**
 * 同 154
 * 但如果太多重複值的情況下
 * 根本無法判斷去向
 *
 * [1, 10, 10, 10, 10, 10, 10]
 *  0           m           6
 *
 * [1, 10, 10, 10, 10, 10, 10] => [10, 10, 10, 10, 1, 10, 10]
 *          6   0           m       0           m          6
 *
 * [1, 10, 10, 10, 10, 10, 10] => [10, 10, 1, 10, 10, 10, 10]
 *      m           6   0           0          m           6
 *
 * 要觸發這個條件
 * 必須有過半一樣的元素
 */

/**
 * [1, 1]
 * left = 0, right = 2, mid = 1
 *
 * [1, 1, 1]
 * left = 0, right = 3, mid = 1
 *
 * [1, 1, 1, 1]
 * left = 0, right = 4, mid = 2
 *
 */

class Solution {
 public:
  int findMin(vector<int>& nums) { return helper(nums, 0, nums.size()); }

  int helper(vector<int>& nums, int left, int right) {
    if (left >= right) return nums[left];

    int mid = (left + right) / 2;

    // 如果前一位比較大
    // 那我就是答案
    if (mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];

    // 右邊比較小
    // 往小的那邊去
    if (nums[mid] > nums[right - 1]) {
      // 因為右邊一定有答案
      // 所以不可能往右出界
      return helper(nums, mid + 1, right);
    }

    // 左右都相同判斷不了
    // 只好兩邊都做
    if (nums[left] == nums[mid] && nums[mid] == nums[right - 1]) {
      int leftResult = helper(nums, left, mid);
      // 往右會出界
      if (mid + 1 == right) return leftResult;

      return min(leftResult, helper(nums, mid + 1, right));
    }

    // 會有右側比較大
    // 左側一樣的情境嗎？
    // 會的 [10, 10, 10, 11, 12]
    // 是往左走沒錯
    // 但可以確定答案
    if (nums[left] == nums[mid]) return nums[mid];

    // 右邊比較大
    // 答案一定在左邊
    return helper(nums, left, mid);
  }
};
