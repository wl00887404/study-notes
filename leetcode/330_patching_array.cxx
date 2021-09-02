#include <iostream>
#include <vector>

using namespace std;

/**
 * 一個已排序陣列
 * 每個元素只能使用一次
 * 要能又湊出 1 ~ n 的數字
 * nums = [1, 3], n = 6 補上 2 即可
 * 1 = 1
 * 2 = 2
 * 3 = 3
 * 4 = 1 + 3
 * 5 = 2 + 3
 * 6 = 1 + 2 + 3
 *
 * 這一題看起來就是 2 進位
 *
 * nums = [1, 1, 1, 1], n = 9
 * 1 = 1
 * 2 = 1 + 1 (原本應該是 2)
 * 3 = 2 + 1
 * 4 = 1 + 1 + 1 + 1 (原本應該是 4)
 * 5 = 爆炸 要補 5 還是 4 ？
 * 6 = 5 + 1
 * 7 = 5 + 1 + 1
 * 8 = 5 + 1 + 1 + 1
 * 9 = 5 + 1 + 1 + 1 + 1
 * 補 4 沒辦法完成 9
 *
 *
 * 絕對不是 2 進位
 * 假設能夠完成 1 ~ 7 此時來了 2 個 5
 * [1, 2, 4]
 *
 * 5 = 5
 * 6 = 5 + 1
 * 7 = 5 + 2
 * 8 = 5 + 3
 * 9 = 5 + 4
 * 10 = 5 + 5
 * 11 = 5 + 6 (2 + 4)
 *
 * 可以完成 1 ~ n 此時來了 n + 1
 * n + 1 = 補上的
 * n + 2 = n + 1 + 1
 * ...
 * 2 * n  = (n + 1) + (n - 1)
 * 2 * n + 1 = n + 1 + n
 * 2 * n + 2 = (2 * n + 1) + 1
 * 2 * n + 3 = (2 * n + 1) + 2
 * ...
 * 3 * n + 1 = (2 * n + 1) + n
 * 3 * n + 2 = (2 * n + 1) + n + 1
 *
 * 來一個 5 可以 cover  5 + 7
 * 可以完成範圍來到  5 + 5 + 7
 */

/**
 * nums = [1, 2, 31, 33], n = 2147483647
 *  1, nums[0] 來     max = 1
 *  2, 從 nums[1] 來  max = 3
 *  3 小於 max 穩啦
 *  4 出不來補一下     max = 7
 *  8 出不來補一下     max = 15
 * 16 出不來補一下     max = 31
 * 31 有耶可以直接吃   max = 62
 * 可以產生 1 ~ 62    max = 95
 *
 * 不夠可以從 nums 吃
 * nums 沒有就要補 (max < nums[i])
 * 如果 max 比 nums 大那就要吃
 */

class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    unsigned int max = 0; // max 表示能夠完成 [0, n] 的數值
    int patchCount = 0;
    int i = 0;
    int length = nums.size();

    while (max < n) {
      // 下一個要完成 [0, max + 1]
      if (i < length && max + 1 >= nums[i]) {
        // 如果 nums[i] 在新範圍內
        // 那就吃掉 nums[i]
        max += nums[i];
        i++;
      } else {
        // 如果 nums[i] 在範圍外
        // 那就必須 patch 了
        max += max + 1;
        patchCount++;
      }
    }

    return patchCount;
  }
};
