#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "./log.cxx"
using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    if (n == 1) return {{"Q"}};
    if (n == 2 || n == 3) return {};

    vector<string> board;
    vector<vector<string>> results;
    bool xUsed[n];
    stack<int> xStack;

    for (int i = 0; i < n; i++) xUsed[i] = false;
    for (int i = 0; i < n; i++) board.push_back(string(n, '.'));

    int x = 0;
    int y = 0;

    int mid = n / 2 + n % 2 - 1;

    while (true) {
      if (x > mid) {
        if (y == 0) break;
        if (n % 2 && board[0][n / 2] == 'Q' && y == 1) break;
      }

      if (x == n) {
        y--;
        x = xStack.top();
        xStack.pop();
        board[y][x] = '.';
        xUsed[x] = false;
        x++;
        continue;
      }

      if (!isValid(n, board, xUsed, y, x)) {
        x++;
        continue;
      }

      board[y][x] = 'Q';

      if (y == n - 1) {
        results.push_back(board);
        results.push_back(mirror(n, board));

        board[y][x] = '.';
        x = n;

        continue;
      }

      xStack.push(x);
      xUsed[x] = true;
      y++;
      x = 0;
    }

    return results;
  }

  bool isValid(int& n, vector<string>& board, bool xUsed[], int& y, int& x) {
    if (xUsed[x] == true) return false;

    for (int i = 1; i <= y; i++) {
      int left = x - i;
      int right = x + i;

      if (right < n && board[y - i][right] == 'Q') return false;
      if (0 <= left && board[y - i][left] == 'Q') return false;
    }

    return true;
  }

  vector<string> mirror(int& n, vector<string>& board) {
    vector<string> mirrored;

    for (int i = 0; i < n; i++) {
      mirrored.push_back(board[i]);
      reverse(mirrored[i].begin(), mirrored[i].end());
    }

    return mirrored;
  }
} solution;

int main() {
  vector<vector<string>> results = solution.solveNQueens(5);

  log(results);

  return 0;
}