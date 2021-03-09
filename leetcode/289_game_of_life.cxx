#include <iostream>
#include <vector>
using namespace std;
/**
 * 1. Any live cell with fewer than two live neighbors dies as if caused by
 *    under-population.
 * > 活細胞要是身旁少於 2 個活細胞就會死
 * 2. Any live cell with two or three live neighbors lives on to the next
 *    generation.
 * > 活細胞要是身旁有 2-3 個活細胞會繼續活著
 * 3. Any live cell with more than three live neighbors dies, as if by
 *    over-population.
 * > 活細胞要是身旁有超過 3 個活死細胞就會死
 * 4. Any dead cell with exactly three live neighbors becomes a live cell, as if
 *    by reproduction.
 * > 死細胞要是身旁有 3 個活細胞就會活回來
 */

class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    int height = board.size();
    int width = board[0].size();

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (board[i][j] % 10 == 0) continue;

        bool hasTop = i - 1 > -1;
        bool hasBottom = i + 1 < height;
        bool hasLeft = j - 1 > -1;
        bool hasRight = j + 1 < width;

        if (hasLeft && hasTop) board[i - 1][j - 1] += 10;
        if (hasLeft) board[i][j - 1] += 10;
        if (hasLeft && hasBottom) board[i + 1][j - 1] += 10;
        if (hasBottom) board[i + 1][j] += 10;
        if (hasRight && hasBottom) board[i + 1][j + 1] += 10;
        if (hasRight) board[i][j + 1] += 10;
        if (hasRight && hasTop) board[i - 1][j + 1] += 10;
        if (hasTop) board[i - 1][j] += 10;
      }
    }

    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        int neighbors = board[i][j] / 10;
        int isLive = board[i][j] % 10;

        if (isLive) {
          if (neighbors < 2) {
            board[i][j] = 0;
          } else if (neighbors < 4) {
            board[i][j] = 1;
          } else {
            board[i][j] = 0;
          }
        } else {
          if (neighbors == 3) {
            board[i][j] = 1;
          } else {
            board[i][j] = 0;
          }
        }
      }
    }
  }
};