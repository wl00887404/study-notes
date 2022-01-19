#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * O 被圍在起來要變成 X
 * 但是碰到邊邊的 O 不用換
 *
 * 繞一圈 DFS 就解了
 * 不知道為什有時間差耶
 */

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    m = board.size();
    n = board[0].size();
    boardPointer = &board;

    reserveBoard.resize(m);
    for (int i = 0; i < m; i++) {
      reserveBoard[i].resize(n, false);
    }

    for (int i = 0; i < m; i++) {
      reserve(i, 0);
      reserve(i, n - 1);
    }

    for (int j = 1; j < n - 1; j++) {
      reserve(0, j);
      reserve(m - 1, j);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'X') continue;
        if (reserveBoard[i][j]) continue;

        board[i][j] = 'X';
      }
    }
  }

  int m;
  int n;
  vector<vector<char>>* boardPointer;
  vector<vector<bool>> reserveBoard;

  void reserve(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n) return;
    if (reserveBoard[i][j]) return;

    vector<vector<char>>& board = *boardPointer;
    if (board[i][j] == 'X') return;

    reserveBoard[i][j] = true;
    reserve(i + 1, j);
    reserve(i - 1, j);
    reserve(i, j + 1);
    reserve(i, j - 1);
  }
};