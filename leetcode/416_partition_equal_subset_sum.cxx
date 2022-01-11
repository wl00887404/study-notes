#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 題意是給一個陣列
 * 全都是正數
 * 能不能一分為二
 * 讓兩個子集加起來一樣大
 */

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) sum += nums[i];

    // 總和是奇數
    // 怎麼加都不可能
    if (sum % 2 == 1) return false;

    int target = sum / 2;

    unordered_set<int> cache;
    queue<int> queue;
    cache.insert(0);

    for (int i = 0; i < size; i++) {
      for (const int& value : cache) {
        int nextValue = value + nums[i];
        if (nextValue == target) return true;
        if (nextValue > target) continue;

        queue.push(nextValue);
      }

      while (!queue.empty()) {
        cache.insert(queue.front());
        queue.pop();
      }
    }

    return false;
  }
};

/**
 * 只要是「選或不選」 + 「總和為某數」
 * 就很明顯就是背包問題
 * 相關題 322
 *
 * TODO:
 * https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
 * 學一下怎麼用 dp 做背包問題
 * 最佳解有一個 bitset 是用嗎？
 * 4ms 有夠快的
 */