#include <math.h>

#include <iostream>
#include <vector>

#define PI acos(-1)

/**
 * 先決定一個三角形
 * 再慢慢增加點
 * 有點不太可行
 */

/**
 * 這個問題叫做 Convex Hull
 * 自己想出來了 Jarvis' March
 * 真開心
 */

using namespace std;

class Solution {
 public:
  vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    int length = trees.size();

    if (length <= 3) return trees;

    vector<vector<int>> result;
    bool isUsed[length];
    for (int i = 0; i < length; i++) isUsed[i] = false;

    // 先找最下方的點
    int from = 0;
    for (int i = 1; i < length; i++) {
      if (trees[from][1] <= trees[i][1]) continue;

      from = i;
    }

    result.push_back(trees[from]);
    isUsed[from] = true;

    vector<int> vec1 = {1, 0};
    double length1 = 1;

    double minAngle;
    double angles[length];
    double length2s[length];

    while (true) {
      // 找出下一組夾角最小
      minAngle = INFINITY;
      int to = -1;

      for (int i = 0; i < length; i++) {
        if (i == from) continue;
        vector<int> vec2 = {trees[i][0] - trees[from][0],
                            trees[i][1] - trees[from][1]};

        double dotProduct = getDotProduct(vec1, vec2);
        length2s[i] = getLength(vec2);
        angles[i] = getAngle(dotProduct, length1, length2s[i]);

        if (angles[i] > minAngle) continue;

        minAngle = angles[i];
        to = i;
      }

      for (int i = 0; i < length; i++) {
        if (i == from || angles[i] != minAngle) continue;
        if (length2s[to] > length2s[i]) continue;

        to = i;
      }

      for (int i = 0; i < length; i++) {
        if (i == from || angles[i] != minAngle) continue;
        if (i == to) continue;
        if (isUsed[i]) continue;

        isUsed[i] = true;
        result.push_back(trees[i]);
      }

      if (isUsed[to]) break;

      isUsed[to] = true;
      result.push_back(trees[to]);
      vec1[0] = trees[to][0] - trees[from][0];
      vec1[1] = trees[to][1] - trees[from][1];
      length1 = length2s[to];

      from = to;
    }

    return result;
  }

  double getLength(vector<int>& vec) {
    return sqrt(pow(vec[0], 2) + pow(vec[1], 2));
  }

  double getDotProduct(vector<int>& vec1, vector<int>& vec2) {
    return vec1[0] * vec2[0] + vec1[1] * vec2[1];
  }

  double getAngle(double& dotProduct, double& length1, double& length2) {
    return round(acos(max(-1.0, min(1.0, dotProduct / length1 / length2))) *
                 1000);
  }
} solution;

int main() {
  // vector<vector<int>> trees = {{5, 5}, {4, 8}, {1, 3}, {5, 9}, {3, 0},
  //                              {0, 4}, {3, 2}, {8, 9}, {9, 3}};
  vector<vector<int>> trees = {{0, 2}, {0, 9}, {1, 2}, {1, 4}, {2, 9}, {3, 7},
                               {5, 4}, {5, 8}, {6, 2}, {6, 4}, {6, 9}, {7, 3},
                               {7, 4}, {7, 9}, {9, 4}, {9, 6}, {9, 7}, {9, 8}};

  solution.outerTrees(trees);

  return 0;
}