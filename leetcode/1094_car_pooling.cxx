#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 不知道難度在哪耶
 * 不就乖乖上下車
 * 看什麼時候會爆掉嗎？
 */

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int peopleCount = 0;
    // 時間, 人數變化
    vector<pair<int, int>> deltas;

    for (vector<int>& trip : trips) {
      deltas.push_back({trip[1], trip[0]});
      deltas.push_back({trip[2], -1 * trip[0]});
    }

    sort(deltas.begin(), deltas.end());

    for (pair<int, int>& delta : deltas) {
      peopleCount += delta.second;

      if (peopleCount > capacity) return false;
    }

    return true;
  }
};