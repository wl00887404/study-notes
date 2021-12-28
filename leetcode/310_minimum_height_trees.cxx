#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 撥洋蔥 RRRR
 * 可是 128 ms 到底是三小
 *
 * TODO: 敢不敢快一點
 */

/**
 * 2021/12/16 的每日
 * 靠北我有寫過喔
 *
 * 步驟看來
 * 迭代一次 edges 可以知道誰是葉子
 * 移除葉子節點
 * => 要是剩下節點 <= 2 就是答案
 * 移除葉子相關 edge
 *
 * 問題就在移除葉子相關 edge
 * 查詢這些 edge 會再迭代一次 edges
 * 移除也要花 O(n)
 */

/**
 * TODO:
 *   看一下最佳解怎麼做的
 *   我的程式碼又臭又長耶
 *   不能從葉子往上爬啦
 *   這組不會過
 *   n = 7
 *   edges = [[0, 1], [1, 2], [1, 3], [2, 4], [3, 5], [4, 6]]
 */

/**
 * 想起來了跟 207 有關連
 * 207 沒有特別做什麼優化手段
 *
 * 隨意寫的「沒特別優化」
 * 實際跑出來的數字差不多
 */

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};

    int frequencies[n];
    vector<int> edgesByNode[n];

    for (int i = 0; i < n; i++) frequencies[i] = 0;

    for (vector<int>& edge : edges) {
      for (int& node : edge) {
        frequencies[node]++;
      }

      edgesByNode[edge[0]].push_back(edge[1]);
      edgesByNode[edge[1]].push_back(edge[0]);
    }

    int remain = n;
    queue<int> queue;

    while (remain > 2) {
      for (int i = 0; i < n; i++) {
        if (frequencies[i] != 1) continue;
        // 找到葉子了

        queue.push(i);
        frequencies[i] = 0;
        remain--;
      }

      if (remain <= 2) break;

      while (!queue.empty()) {
        int& i = queue.front();
        for (int& node : edgesByNode[i]) {
          frequencies[node] = max(0, frequencies[node] - 1);
        }
        queue.pop();
      }
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
      if (frequencies[i] == 0) continue;

      result.push_back(i);
    }

    return result;
  }
};

class OldSolution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> result;
    unordered_set<int> nodes[n];

    int size = edges.size();
    for (int i = 0; i < size; i++) {
      int n1 = edges[i][0];
      int n2 = edges[i][1];

      nodes[n1].insert(n2);
      nodes[n2].insert(n1);
    }

    unordered_set<int> leave;
    bool isLeaf[n];
    for (int i = 0; i < n; i++) isLeaf[i] = false;

    while (true) {
      if (leave.size() != 0) leave.clear();

      bool isFinished = true;
      for (int i = 0; i < n; i++) {
        if (nodes[i].size() < 2) continue;

        isFinished = false;
        break;
      }

      if (isFinished) break;

      for (int i = 0; i < n; i++) {
        if (nodes[i].size() != 1) continue;

        leave.insert(i);
      }

      for (auto it = leave.begin(); it != leave.end(); it++) {
        isLeaf[*it] = true;
        nodes[*(nodes[*it].begin())].erase(*it);
        nodes[*it].clear();
      }
    }

    for (int i = 0; i < n; i++) {
      if (isLeaf[i]) continue;

      result.push_back(i);
    }

    return result;
  }
} solution;

int main() {
  vector<vector<int>> edges;
  vector<int> result;

  // edges = {{1, 0}, {1, 2}, {1, 3}};
  // result = solution.findMinHeightTrees(4, edges);

  edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
  result = solution.findMinHeightTrees(6, edges);

  // edges = {{0, 1}};
  // result = solution.findMinHeightTrees(2, edges);

  return 0;
}