#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define END 2
#define BEGIN 1
#define SPACE 0
#define OBSTACLE -1

/**
 * 不知道有沒有比較快的方式
 * 先來 DFS 瘋狂迷宮好了
 */

class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    gridPointer = &grid;
    mSize = grid.size();
    nSize = grid[0].size();

    for (int m = 0; m < mSize; m++) {
      for (int n = 0; n < nSize; n++) {
        switch (grid[m][n]) {
          case BEGIN:
            current = {m, n};
            break;
          case END:
            end = {m, n};
            break;
          case OBSTACLE:
            break;
          default:
            stepCount++;
            break;
        }
      }
    }

    helper();

    return result;
  }

 private:
  int stepCount = 1;
  int mSize;
  int nSize;
  pair<int, int> end;
  int result = 0;

  pair<int, int> current;

  vector<vector<int>>* gridPointer;

  void helper() {
    int& m = current.first;
    int& n = current.second;
    vector<vector<int>>& grid = *gridPointer;

    if (grid[m][n] == END) {
      if (stepCount == 0) result++;
      return;
    }

    grid[m][n] = OBSTACLE;
    stepCount--;

    // 上
    if (0 <= m - 1 && grid[m - 1][n] != OBSTACLE) {
      m--;
      helper();
      m++;
    }

    // 右
    if (n + 1 < nSize && grid[m][n + 1] != OBSTACLE) {
      n++;
      helper();
      n--;
    }

    // 下
    if (m + 1 < mSize && grid[m + 1][n] != OBSTACLE) {
      m++;
      helper();
      m--;
    }

    // 左
    if (0 <= n - 1 && grid[m][n - 1] != OBSTACLE) {
      n--;
      helper();
      n++;
    }

    grid[m][n] = SPACE;
    stepCount++;
  };
};