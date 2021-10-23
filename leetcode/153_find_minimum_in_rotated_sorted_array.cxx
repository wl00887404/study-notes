
#include <iostream>
#include <vector>
using namespace std;

/**
 * 與 33 題很像
 * 我那時候覺得超難
 * 我想這題也不例外 = =
 */

/**
 * 同樣的概念 binary search
 * 只要朝對的移動的方向對就好
 *
 * [0, 1, 2, 3, 4, 5, 6] => 往左
 *  0        m        6
 *
 * [0, 1, 2, 3, 4, 5, 6] => [6, 0, 1, 2, 3, 4, 5] => 往左
 *        m        6  0               m
 *
 * [0, 1, 2, 3, 4, 5, 6] => [1, 2, 3, 4, 5, 6, 0] => 往右
 *  6  0        m                     m
 */
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int mid = (left + right) / 2;

      // 如果前一位比較大
      // 那我就是答案
      if (mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];

      if (nums[mid] > nums[right - 1]) {
        // 右邊比較小
        // 往小的那邊去
        left = mid + 1;
      } else {
        // 右邊比較大
        // 答案一定在左邊
        right = mid;
      }
    }

    return nums[left];
  };
};

int main() {
  vector<int> nums = {0, 1, 2, 3, 4, 5, 6};

  return 0;
}
