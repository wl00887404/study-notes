#include <iostream>
#include <list>
#include <queue>
#include <unordered_set>

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

/**
 * Ascii 樹產生器：
 *   https://ascii-tree-generator.com/
 */

/**
 * 換個想法
 * 找出樹的中心點（到葉子的深度一樣）
 * 這個點一定是距離最短的
 *
 * n = 8, edges = [[0, 1], [0, 2], [1,3], [1, 4], [2, 5], [2,6],[2,7]]
 *
 * 0
 * ├── 1
 * │   ├── 3
 * │   └── 4
 * └── 2
 *     ├── 5
 *     ├── 6
 *     └── 7

 * |     | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
 * | --- | --- | --- | --- | --- | --- | --- | --- | --- |
 * | 0   | 0   | 1   | 1   | 2   | 2   | 2   | 2   | 2   | = 12
 * | 1   | 1   | 0   | 2   | 1   | 1   | 3   | 3   | 3   | = 14
 *
 * 從 0 移到 1
 * [0, 3] 少了 [0, 1] 成了 [1, 3]
 * [0, 4] 少了 [0, 1] 成了 [1, 4]
 * [0, 2] 多了 [0, 1] 成了 [1, 2]
 * [0, 5] 多了 [0, 1] 成了 [1, 5]
 * [0, 6] 多了 [0, 1] 成了 [1, 6]
 * [0, 7] 多了 [0, 1] 成了 [1, 7]
 * 也就是 - 2 (3, 4) + 4 (2, 5, 6, 7)
 * 照這個模式可以推完全部
 *
 * n = 7, edges = [[0, 1], [0, 2], [0, 3], [0, 4], [1, 5], [1, 6]]
 *
 * ├── 0
 * │   ├── 2
 * │   ├── 3
 * │   └── 4
 * └── 1
 *     ├── 5
 *     └── 6
 *
 * |     | 0   | 1   | 2   | 3   | 4   | 5   | 6   |
 * | --- | --- | --- | --- | --- | --- | --- | --- |
 * | 0   | 0   | 1   | 1   | 1   | 1   | 2   | 2   | = 8
 * | 1   | 1   | 0   | 2   | 2   | 2   | 1   | 1   | = 9
 *
 * 怎麼找中心點？
 * 葉子往上執行，一併計算長度總和，每個點要計算自己的 descendantCount
 */

/**
 * 不用找中心點
 * 改成節點每個方向有多少的 children
 */

/**
 * 其實隨便找一個節點當頭就可以了
 */

class Solution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int> result(n);
    list<int> nthChildren[n];  // 用以快搜跟 n 有關的 edge

    int nthDescendantCount[n];  // 0 為首的方向，後裔的數量
    for (int i = 0; i < n; i++) nthDescendantCount[i] = 0;

    for (int i = 0; i < n - 1; i++) {
      vector<int>& edge = edges[i];
      nthChildren[edge[0]].push_back(edge[1]);
      nthChildren[edge[1]].push_back(edge[0]);
    }

    // 0 為首，往下跑
    calcDescendantCount(nthChildren, nthDescendantCount, -1, 0);
    result[0] = calcResult(0, nthChildren);

    calcResults(n, result, nthChildren, nthDescendantCount, 0);

    return result;
  }

  void calcDescendantCount(list<int>* nthChildren, int* nthDescendantCount,
                           int parent, int current) {
    list<int>& children = nthChildren[current];

    list<int>::iterator begin = children.begin();
    list<int>::iterator end = children.end();

    while (begin != end) {
      int& child = *begin;
      if (child == parent) {
        begin = children.erase(begin);
      } else {
        calcDescendantCount(nthChildren, nthDescendantCount, current, child);
        nthDescendantCount[current] += nthDescendantCount[child] + 1;
        begin++;
      }
    }
  }

  int calcResult(int i, list<int>* nthChildren) {
    int depth = 0;
    int result = 0;
    queue<int> queue;
    queue.push(i);

    while (!queue.empty()) {
      int length = queue.size();
      result += length * depth;

      while (length--) {
        for (int& child : nthChildren[queue.front()]) {
          queue.push(child);
        }
        queue.pop();
      }

      depth++;
    }

    return result;
  }

  void calcResults(int& n, vector<int>& result, list<int>* nthChildren,
                   int* nthDescendantCount, int parent) {
    for (int& child : nthChildren[parent]) {
      // 移動到子節點
      // = 爸爸的結果 - 自己的後裔數 + 同層其他子節點的後裔
      // = 爸爸的結果 - 自己的後裔數 + ( 總數 - 自己的後裔數 - 自己 - 爸爸 )

      result[child] = result[parent] + n - 2 * nthDescendantCount[child] - 2;
      calcResults(n, result, nthChildren, nthDescendantCount, child);
    }
  }
} solution;

class TimeLimitExceededSolution {
 public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int> nthChildren[n];

    int edgeSize = edges.size();
    for (int i = 0; i < edgeSize; i++) {
      nthChildren[edges[i][0]].push_back(edges[i][1]);
      nthChildren[edges[i][1]].push_back(edges[i][0]);
    }

    queue<int> queue;
    vector<int> result(n);
    int isUsed[n];
    for (int i = 0; i < n; i++) {
      result[i] = 0;
      int depth = 1;
      for (int j = 0; j < n; j++) isUsed[j] = false;
      queue.push(i);

      while (!queue.empty()) {
        int size = queue.size();

        while (size--) {
          isUsed[queue.front()] = true;
          vector<int>& children = nthChildren[queue.front()];
          for (int j = 0; j < children.size(); j++) {
            if (isUsed[children[j]]) continue;
            result[i] += depth;

            queue.push(children[j]);
          }

          queue.pop();
        }
        depth++;
      }
    }

    return result;
  }
};

int main() {
  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};

  solution.sumOfDistancesInTree(n, edges);

  return 0;
}
