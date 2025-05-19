#include <queue>
#include <vector>
using namespace std;

/**
 * 給一個 m * n 陣列
 * 時間到了房間才會開門，移動到隔壁房間也會花 1 單位，不能斜走
 */

/**
 * TODO: 每日一題偷抄作業，下次補
 */

int MAX_DISTANCE = 1000000001;

class Solution {
 public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int m = moveTime.size();
    int n = moveTime[0].size();
    vector<vector<int>> distances(m, vector<int>(n, MAX_DISTANCE));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   less<pair<int, pair<int, int>>>>
        pq;

    pq.push({0, {0, 0}});

    while (!pq.empty()) {
      int distance = pq.top().first;
      int i = pq.top().second.first;
      int j = pq.top().second.second;
      pq.pop();

      // 這是一個比較遠的到達方法
      if (distance >= distances[i][j]) continue;

      distances[i][j] = distance;

      // 往上
      if (i - 1 >= 0) {
        int nextDistance = max(distance, moveTime[i - 1][j]) + 1;
        pq.push({nextDistance, {i - 1, j}});
      }
      // 往右
      if (j + 1 < n) {
        int nextDistance = max(distance, moveTime[i][j + 1]) + 1;
        pq.push({nextDistance, {i, j + 1}});
      }
      // 往下
      if (i + 1 < m) {
        int nextDistance = max(distance, moveTime[i + 1][j]) + 1;
        pq.push({nextDistance, {i + 1, j}});
      }
      // 往左
      if (j - 1 > 0) {
        int nextDistance = max(distance, moveTime[i][j - 1]) + 1;
        pq.push({nextDistance, {i, j - 1}});
      }
    }

    return distances[m - 1][n - 1];
  }
};