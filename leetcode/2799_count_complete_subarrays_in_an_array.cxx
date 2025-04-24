#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 找到最小的完全子陣列？
 *
 * 從一個空陣列開始
 * 不滿足 => 往右加入一個元素
 * 已滿足 => 右邊的元素全加進來都會是完全子陣列 => 左側排掉一個元素
 */

/**
 * 完全 => 新增元素 => 依然完全
 *
 * 不完全 => 新增元素 => 可能完全
 * 完全 => 刪掉元素 => 可能還是完全
 */

class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    int size = nums.size();
    unordered_map<int, int> map;

    for (const int& num : nums) {
      map[num]++;
    }

    int completeSize = map.size();
    map.clear();

    int left = 0;
    int right = 0;
    int result = 0;

    while (left < size && right < size) {
      // 往右擴張以試圖成為完全子陣列
      map[nums[right]]++;

      if (map.size() == completeSize) {
        result += size - right;  // 自己往右全部的元素都可以形成完全子陣列

        while (left < size) {
          int& leftNum = nums[left];
          map[leftNum]--;  // 排除掉最左側的元素
          left++;

          // 這元素被刪掉了，竟然還有剩，依然是完全子陣列
          if (map[leftNum] != 0) {
            result += size - right;
          } else {
            map.erase(leftNum);
            break;
          }
        }
      }

      right++;
    }

    return result;
  }
};