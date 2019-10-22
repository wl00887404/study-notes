#include <iostream>
#include <vector>
using namespace std;

// 列出所有 paths 大爆炸

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    bool has[n] = {false};
    int paths[n][n] = {0};

    int length = edges.size();
    for (int i = 0; i < length; i++) {
      int n1 = edges[i][0];
      int n2 = edges[i][1];

      if (!has[n1] && !has[n2]) {
        paths[n1][n2] = 1;
        paths[n2][n1] = 1;
        has[n1] = true;
        has[n2] = true;
        continue;
      }

      if (!has[n1]) swap(n1, n2);
      // n2 是新節點

      for (int j = 0; j < n; j++) {
        if (!has[j]) continue;
        paths[j][n2] = paths[j][n1] + 1;
        paths[n2][j] = paths[j][n1] + 1;
      }

      has[n2] = true;
    }

    // 找到最短的的那棵樹
    int heights[n] = {0};
    int min = n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        if (paths[i][j] > heights[i]) heights[i] = paths[i][j];

      if (min > heights[i]) min = heights[i];
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
      if (heights[i] == min) result.push_back(i);
    }

    return result;
  }

  void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
  }
} solution;

int main() {
  // vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
  // vector<int> result = solution.findMinHeightTrees(4, edges);

  vector<vector<int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
  vector<int> result = solution.findMinHeightTrees(6, edges);

  int size = result.size();
  cout << "{ ";
  for (int i = 0; i < size; i++) {
    cout << result[i];
    if (i != size - 1) cout << ", ";
  }
  cout << " }" << endl;

  return 0;
}