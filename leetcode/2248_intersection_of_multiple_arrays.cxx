#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 要讓 nums 元素要完全一致
 * 只能調整元素 +1 -1，每次調整 nums[i] 會消耗 cost[i]
 */

/**
 * nums = [1, 3, 5, 2], cost = [2, 3, 1, 14]
 * 大家要一樣，結果為 x
 * 花費 = abs(x - 1) * 2 + abs(x - 3) * 3 + abs(x - 5) * 1 + abs(x - 2) * 14
 * 算一次是 O(n)
 * nums 為 1 ~ 5，r 值一定在這個範圍內，可以讓其中某一項為 0
 * 花費的圖形畫起來會是一個大 V ，要找它的最低點
 * 那就是一個二分搜尋？
 */

class TimeLimitExceededSolution {
 public:
  int size;
  vector<int>* numsP;
  vector<int>* costP;
  unordered_set<int> set;

  long long minCost(vector<int>& nums, vector<int>& cost) {
    numsP = &nums;
    costP = &cost;
    size = nums.size();

    long long result = LLONG_MAX;
    for (int i = 0; i < size; i++) {
      if (set.count(nums[i])) continue;
      result = min(result, getCost(nums[i]));
      set.insert(nums[i]);
    }

    return result;
  }

  long long getCost(int x) {
    vector<int>& nums = *numsP;
    vector<int>& cost = *costP;

    long long result = 0;
    for (int i = 0; i < size; i++) {
      result += (long long)abs(nums[i] - x) * cost[i];
    }

    return result;
  }
};

/**
 * 二分搜尋不知道怎麼取捨 left right ，不可行
 * 取一次 cost 是 O(n)，每個點都取，結果會是 O(n^2)
 * 還不如排序後比斜率 O(nlogn) 快
 * 絕對值函數最低點發生在折射位置，斜率會由正轉負
 */
class Solution {
 public:
  Solution() {
    // 突然又從範例答案看到的神秘巫術
    // 應該是關閉 IO ，讓速度快很多
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
  int size;
  vector<pair<int, int>> numsWithCost;

  long long minCost(vector<int>& nums, vector<int>& cost) {
    size = nums.size();
    numsWithCost.resize(size);
    for (int i = 0; i < size; i++) {
      numsWithCost[i] = {nums[i], cost[i]};
    }

    sort(numsWithCost.begin(), numsWithCost.end());

    long long slope = getSlope();  // 最後一個點的斜率
    int i = size - 1;

    while (true) {
      // 最後一點由正轉負
      // 也就是 abs(x - 5) * 10 ，大於等於 5 時，是 10 * x - 50
      // 但是小於 5 時，是  50 - 10 * x
      // 兩者差 10 * x * 2
      long long nextSlope = slope - numsWithCost[i].second * 2;
      if (nextSlope < 0) break;
      slope = nextSlope;
      i--;
    }

    return getCost(numsWithCost[i].first);
  }

  long long getSlope() {
    long long slope = 0;
    for (int i = 0; i < size; i++) {
      slope += numsWithCost[i].second;
    }
    return slope;
  }

  long long getCost(int x) {
    long long result = 0;
    for (int i = 0; i < size; i++) {
      int& num = numsWithCost[i].first;
      int& cost = numsWithCost[i].second;
      result += (long long)abs(num - x) * cost;
    }

    return result;
  }
};