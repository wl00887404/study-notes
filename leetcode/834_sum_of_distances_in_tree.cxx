#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/**
 * 距離表怎麼樣
 * n = 6, edges = [[0, 1], [0, 2], [2, 3], [2, 4],[2, 5]]
 *
 * 當 [m, n] 出現
 * m 左側節點全部都要更新
 * n 右側節點也全部都要更新
 * 看起來挺頭痛的
 */

/**
 * 距離表 + pedding 沒辦法接上去的節點
 * 這個做法會超時 😢
 */

class TimeLimitExceededSolution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};

    bool isUsed[n];
    for (int i = 0; i < n; i++) isUsed[i] = 0;
    vector<vector<int>> distances(n);
    for (int i = 0; i < n; i++) {
      distances[i] = vector<int>(n);
    }

    queue<vector<int>*> queue;

    distances[edges[0][0]][edges[0][1]] = 1;
    distances[edges[0][1]][edges[0][0]] = 1;
    isUsed[edges[0][0]] = true;
    isUsed[edges[0][1]] = true;

    // 把所有 edge 丟進 queue
    for (int i = 1; i < n - 1; i++) queue.push(&edges[i]);

    while (!queue.empty()) {
      vector<int>& edge = *queue.front();
      int& from = edge[0];
      int& to = edge[1];

      queue.pop();

      if (!isUsed[from] && !isUsed[to]) {
        queue.push(&edge);
        continue;
      }

      int& usedIndex = isUsed[from] ? from : to;
      int& unusedIndex = !isUsed[from] ? from : to;

      distances[from][to] = distances[to][from] = 1;

      for (int i = 0; i < n; i++) {
        if (unusedIndex == i || distances[i][usedIndex] == 0) continue;
        // 已有 [0, 1] [1, 0]
        // 此時 [0, 2] 加入
        // [1, 2] 等同於 [1, 0] + [0, 2]
        distances[unusedIndex][i] = distances[i][unusedIndex] =
            distances[i][usedIndex] + distances[usedIndex][unusedIndex];
      }

      isUsed[unusedIndex] = true;
    }

    vector<int> result(n);
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) sum += distances[i][j];
      result[i] = sum;
    }

    return result;
  }
} solution;

int main() {
  // int n = 6;
  // vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};

  // int n = 4;
  // vector<vector<int>> edges = {{2, 0}, {3, 1}, {2, 1}};

  int x[1000][1000];
  return 0;

  // solution.sumOfDistancesInTree(n, edges);

  return 0;
}
