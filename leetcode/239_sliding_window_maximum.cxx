#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 這題要是能用 priority_queue 的話
 * 應該沒有 hard
 */

/**
 * TODO:
 * 提示說用 deque 解
 * 應該要研究一下
 */

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> pq;
    vector<int> result;
    int size = nums.size();

    for (int i = 0; i < k; i++) {
      pq.push({nums[i], i});
    }
    result.push_back(pq.top().first);

    for (int i = k; i < size; i++) {
      pq.push({nums[i], i});
      // 現在的最大值在 window 外面
      while (pq.top().second <= i - k) {
        pq.pop();
      }

      result.push_back(pq.top().first);
    }

    return result;
  }
};