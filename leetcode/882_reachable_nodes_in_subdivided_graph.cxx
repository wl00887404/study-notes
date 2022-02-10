#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * n 是總結點數
 * maxMoves 表示能夠往外走多少次
 * edge 為 {node1, node2, smallNodeCount}
 * 中間的小節點都是直接連接，沒有分支
 *
 * 就從 0 開始輻射外擴 BFS
 * 為了處理已經到過的 smallNodeCount
 * 經過就就把點刪掉就行了
 *
 * 這樣 BFS 還是 DFS 都可以吧
 */

/**
 * 上述的作法行不通
 * 直接扣掉 smallNodeCount 這個作法行不通
 * 假設到某一個點，到下一個點 smallNodeCount 為 6
 * 第一次到 maxMoves 為 2
 * 第二次到 maxMoves 為 4
 *
 * 這樣分不出來要加多少點
 */

/**
 * 不對不對
 * 關鍵字如果是最短距離
 * 假設 maxMoves = 5
 * [0, 2] 直線距離是 8 最短距離是 4
 * 表示前面 5 與後面 1
 * 這個邊長可以佔掉 6 個節點
 *
 * 直線距離與最短距離相同
 * 直線距離 > maxMoves
 * 表示到不了對面，從其他節點也繞不回去
 * maxMoves > 直線距離
 * 表示可以直接通過去
 *
 * 所以我必須依照所有 edges 找到他們的最短距離
 */

/**
 * 看一下戴克斯特拉演算法 Dijkstra's algorithm
 * 除了可以找出 A 到 B 的最短路徑
 * 還可以建出到所有節點的最短路徑樹耶
 * 好屌喔
 */

/**
 * Dijkstra's algorithm
 * 起點是 value 是 0
 * 可以連結的點更新 value 為 0 + cost
 * 跳到現在 value 最低的點
 * 依據新點可以連結的點再次更新權重
 */

class Solution {
 public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    // cost, next node
    for (vector<int>& edge : edges) {
      map[edge[0]].push_back({edge[2], edge[1]});
      map[edge[1]].push_back({edge[2], edge[0]});
    }

    int shortDistances[n];
    for (int i = 0; i < n; i++) shortDistances[i] = 1000000001;

    // cost, next node
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});

    while (!pq.empty()) {
      int node = pq.top().second;     // 現在節點
      int distance = pq.top().first;  // 現在從 0 到這個距離
      pq.pop();

      // 新的走法的距離比現在最短距離還要遠
      if (distance >= shortDistances[node]) continue;

      // 發現新的最短距離
      // 可以更新這個節點相關的節點
      shortDistances[node] = distance;

      for (pair<int, int>& p : map[node]) {
        pq.push({distance + p.first + 1, p.second});
      }
    }

    int result = 0;

    for (vector<int>& edge : edges) {
      // 走到節點 1 還剩下的步數
      int remainingMove1 = max(maxMoves - shortDistances[edge[0]], 0);
      // 走到節點 2 還剩下的步數
      int remainingMove2 = max(maxMoves - shortDistances[edge[1]], 0);

      // 剩餘步數與可以與 smallNodeCount 選一個小的
      result += min(remainingMove1 + remainingMove2, edge[2]);
    }

    // 加上所有可到達節點
    for (int i = 0; i < n; i++) {
      if (shortDistances[i] > maxMoves) continue;

      result++;
    }

    return result;
  }

  unordered_map<int, vector<pair<int, int>>> map;
};