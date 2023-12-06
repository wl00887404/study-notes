#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * 2023/9/18
 * FIXME: 未完成
 */

/**
 * 題意：只有兩個操作，可以 *2 ，或是 -1 ，問要操作幾次才能達到目標
 *
 * 這是數學題吧
 * *2 一定是偶數
 *
 * 欸不對
 * 應該是二進位思考
 * *2 表示向左位移
 * -1 比較麻煩
 * 如果有 +1 這題就很簡單了
 *
 * Example 1: 2 = 10, 3 = 11
 * *2 => 4 = 100
 * -1 => 3 = 011
 *
 * Example 2: 5 = 101, 8 = 1000
 * -1 => 100
 * *2 => 1000
 *
 * Example 3: 3 = 11, 10 = 1010
 * *2 => 110
 * -1 => 101
 * *2 => 1010
 *
 * 目標的 tail 0 可以直接砍掉
 * 因為用 *2 就可以達成了
 *
 * 觀察從 1 做出來呢？
 *
 * 2 (10) => 1 * 2 = 10
 * 3 (11) => 10 * 2 => 100 - 1 = 11
 * 4 (100) => 10 * 2 = 100
 * 5 (101) => 11 * 2 = 110 - 1 = 101
 *
 * 101010 來自 101011
 * 101011 來自 101100
 */

/**
 * 2023/9/25 看來是沒什麼想法 XDD
 * 觀察看上次出錯的答案
 * 難過一點就暴搜
 *
 * 如果 startValue > target 的話
 * 應該就只能一直 -1 吧
 */

class Solution {
 public:
  int brokenCalc(int startValue, int target) {
    this->target = target;

    return helper(startValue);
  }

  int target;
  unordered_map<int, int> cache;

  int helper(int startValue) {
    if (startValue >= target) return startValue - target;

    if (cache.count(startValue)) return cache[startValue];

    cache[startValue] = 1 + helper(startValue * 2);

    if (startValue != 1) {
      cache[startValue] = min(cache[startValue], 1 + cache[startValue - 1]);
    }

    return cache[startValue];
  }
};