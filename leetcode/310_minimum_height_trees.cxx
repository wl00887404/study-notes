#include <chrono>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 撥洋蔥 RRRR
 * 可是 128 ms 到底是三小
 *
 * TODO: 敢不敢快一點
 */

class Solution {
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
    bool isLeaf[n] = {false};

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