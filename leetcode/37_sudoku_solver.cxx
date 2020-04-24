#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 *  28ms 實在太慢 = =
 *
 *  TODO: 敢不敢再快一點
 */

class Solution {
 public:
  void solveSudoku(vector<vector<char>> &board) {
    stack<int> steps;
    int int_board[9][9] = {0};
    int k = 0;

    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        int_board[i][j] = c2i(board[i][j]);
      }

    while (k < 81) {
      int i = k / 9;
      int j = k % 9;

      if (board[i][j] != '.') {
        k++;
        continue;
      }

      int_board[i][j]++;
      if (int_board[i][j] == 10) {
        int_board[i][j] = 0;
        k = steps.top();
        steps.pop();
        continue;
      }

      if (!isValid(int_board, i, j)) continue;

      steps.push(k);
      k++;
    }

    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++) board[i][j] = i2c(int_board[i][j]);
  }

  bool isValid(int board[9][9], int row, int column) {
    return isRowValid(board, row) && isColumnValid(board, column) &&
           isBoxValid(board, row, column);
  }

  bool isRowValid(int board[9][9], int row) {
    bool has[9] = {false};

    for (int i = 0; i < 9; i++) {
      int index = board[row][i] - 1;

      if (index == -1) continue;

      if (has[index]) return false;

      has[index] = true;
    }

    return true;
  }

  bool isColumnValid(int board[9][9], int column) {
    bool has[9] = {false};

    for (int i = 0; i < 9; i++) {
      int index = board[i][column] - 1;

      if (index == -1) continue;

      if (has[index]) return false;

      has[index] = true;
    }

    return true;
  }

  bool isBoxValid(int board[9][9], int row, int column) {
    int top = row / 3 * 3;
    int left = column / 3 * 3;
    bool has[9] = {false};

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        int index = board[top + i][left + j] - 1;

        if (index == -1) continue;

        if (has[index]) return false;

        has[index] = true;
      }
    }

    return true;
  }

  int c2i(char c) { return c - '0'; }
  char i2c(int i) { return i + '0'; }
} solution;

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  solution.solveSudoku(board);

  return 0;
}