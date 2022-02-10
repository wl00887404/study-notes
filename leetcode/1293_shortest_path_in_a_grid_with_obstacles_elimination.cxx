#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

#define SPACE 0
#define OBSTACLE 1

/**
 * 回來思考這一題
 * 最快路徑依序為
 *   右 + 下
 *   右 + 下 + 炸彈 * 1
 *   右 + 下 + 炸彈 * 2
 *   ...
 *   右 + 下 + 上或左 * 1
 *   右 + 下 + 上或左 * 1 + 炸彈 * 1
 *   右 + 下 + 上或左 * 2 + 炸彈 * 1
 *
 *
 * 遇到障礙有兩個策略
 * 繞過去或是開炸彈
 */

/**
 * 想想理想的作法
 * 先取得只有右 + 下可以走到哪裡
 * 再試試看穿牆
 */

/**
 * Hint1: Use BFS
 * Hint2: BFS on (x, y, bomb)
 *
 * 跟我原本的想法一樣呀
 */

/**
 * 欸不對，先不要想這麼多，直接走呢？
 * k = 1
 * grid = [[0, 0, 0],
 *         [1, 1, 0],
 *         [0, 0, 0],
 *         [0, 1, 1],
 *         [0, 0, 0]]
 *
 * (0, 0, 1) 出發
 * 往右 (0, 1, 1) 可以
 * 往下 (1, 0, 0) 可以
 * queue 有 (0, 1, 1) (1, 0, 0)
 *
 * (0, 1, 1) 出發
 * 往左 (0, 0, 1) ，此點最佳炸彈一樣，停止
 * 左下 (0)
 *
 */

struct Step {
  int i;
  int j;
  int remainingBomb;

  Step(int i, int j, int remainingBomb)
      : i(i), j(j), remainingBomb(remainingBomb){};
};

class Solution {
 public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    m = grid.size();
    n = grid[0].size();

    // 因為下面結果是以「走下一步」
    // 1 * 1 就走不了了
    // 會造成判斷失敗
    if (m == 1 && n == 1) return 0;

    // -1 表示沒有去過
    remainingBombGrid.resize(m, vector<int>(n, -1));
    remainingBombGrid[0][0] = k;
    gridPointer = &grid;

    queue.push(Step(0, 0, k));

    int result = 0;
    while (!queue.empty()) {
      int size = queue.size();
      result++;

      while (size--) {
        int& i = queue.front().i;
        int& j = queue.front().j;
        int& remainingBomb = queue.front().remainingBomb;

        if (move(i - 1, j, remainingBomb)) return result;
        if (move(i, j + 1, remainingBomb)) return result;
        if (move(i + 1, j, remainingBomb)) return result;
        if (move(i, j - 1, remainingBomb)) return result;
        queue.pop();
      }
    }

    return -1;
  }

  bool move(const int i, const int j, int remainingBomb) {
    if (i == -1 || i == m || j == -1 || j == n) return false;

    vector<vector<int>>& grid = *gridPointer;
    if (grid[i][j] == 1) remainingBomb--;

    // 剩餘炸彈太少不可能走得更遠
    // 剩餘炸彈一樣則表示走過了
    if (remainingBomb <= remainingBombGrid[i][j]) return false;

    // 可以繼續走
    // 剛好走到目標了
    if (i == m - 1 && j == n - 1) return true;

    remainingBombGrid[i][j] = remainingBomb;

    queue.push(Step(i, j, remainingBomb));

    return false;
  }

  int m;
  int n;
  vector<vector<int>> remainingBombGrid;
  vector<vector<int>>* gridPointer;
  queue<Step> queue;
};