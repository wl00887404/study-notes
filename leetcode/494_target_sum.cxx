#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 果然是 282 相關題
 */

/**
 * 直接 O(2^n) 會超時耶
 * 這不太可能呀
 *
 * 就算用 memorize 的
 * 依然會有 2^n 種情況
 */

/**
 * 用 unordered_map 減少過項的次數
 * nums = [1, 1, 0, 1, 1], target = 3
 *
 * 0: 1 可以產生 1, -1
 *    map[ 1] = 1
 *    map[-1] = 1
 *
 * 1: 1 可以產生 2, 0, 0, -2
 *    map[ 2] = 1
 *    map[ 0] = 2
 *    map[-2] = 1
 *
 * 2: 0 可以產生 2, 0, 0, -2, 2, 0, 0, -2
 *
 *
 * 喔喔喔
 * map[新產生的值] += 舊產生的次數
 */

/**
 * TODO: 用 array 取代 unordered_map 做 cache 吧
 */

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int size = nums.size();

    if (size == 1) {
      int result = 0;
      if (nums[0] == target) result++;
      if (-1 * nums[0] == target) result++;
      return result;
    }

    unordered_map<int, int> map[size - 1];
    if (nums[0] == 0) {
      map[0][nums[0]] = 2;
    } else {
      map[0][nums[0]] = 1;
      map[0][-1 * nums[0]] = 1;
    }

    for (int i = 1; i < size - 1; i++) {
      for (const pair<int, int>& p : map[i - 1]) {
        map[i][p.first + nums[i]] += p.second;
        map[i][p.first - nums[i]] += p.second;
      }
      map[i - 1].clear();
    }

    int result = 0;
    if (map[size - 2].count(target + nums[size - 1])) {
      result += map[size - 2][target + nums[size - 1]];
    }

    if (map[size - 2].count(target - nums[size - 1])) {
      result += map[size - 2][target - nums[size - 1]];
    }

    return result;
  }
};
