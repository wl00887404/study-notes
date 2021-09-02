
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
 *  0        m         6
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

      /** 
       * [3, 1, 2] mid = 0 剛好是答案
       * 那下一輪會是 left = 0, right = 1, mid = 0
       * nums[0] > nums[0] == false, right = mid 回傳錯誤結果 3
       */

      /**
       * [2, 1] mid = 1 剛好是答案
       * 那下一輪會是 left = 0, right = 1, mid = 0
       * nums[0] > nums[0] == false, right = mid 回傳錯誤結果 2
       */
      if (mid > 0 && nums[mid - 1] > nums[mid]) return nums[mid];
      if (nums[mid] > nums[right - 1]) {
        left = mid + 1;
      } else {
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