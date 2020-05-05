
#include <iostream>
#include <stack>
#include <vector>

#include "./log.cxx"
using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    if (n == 2 || n == 3) return {};

    vector<string> board;
    int result = 0;
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
        result++;
        board[y][x] = '.';
        x = n;

        continue;
      }

      xStack.push(x);
      xUsed[x] = true;
      y++;
      x = 0;
    }

    return result;
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
} solution;

int main() {
  cout << solution.totalNQueens(8) << endl;

  return 0;
}