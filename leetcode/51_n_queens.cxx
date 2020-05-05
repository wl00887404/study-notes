#include <iostream>
#include <stack>
#include <vector>

#include "./log.cxx"
using namespace std;

class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    if (n == 2 || n == 3) return {};

    vector<string> board;
    vector<vector<string>> results;
    bool xUsed[n];
    stack<int> xStack;

    for (int i = 0; i < n; i++) xUsed[i] = false;
    for (int i = 0; i < n; i++) board.push_back(string(n, '.'));
    
    int x = 0;
    int y = 0;

    while (true) {
      if (x == n) {
        if (y == 0) break;

        y--;
        x = xStack.top();
        xStack.pop();
        board[x][y] = '.';
        xUsed[x] = false;
        x++;
        continue;
      }

      if (!isValid(n, board, xUsed, y, x)) {
        x++;
        continue;
      }

      board[x][y] = 'Q';

      if (y == n - 1) {
        results.push_back(board);

        board[x][y] = '.';
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

      if (right < n && board[right][y - i] == 'Q') return false;
      if (0 <= left && board[left][y - i] == 'Q') return false;
    }

    return true;
  }
} solution;

int main() {
  vector<vector<string>> results = solution.solveNQueens(8);

  log(results);

  return 0;
}