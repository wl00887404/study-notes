#include <iostream>
#include <vector>
using namespace std;

/*
 * 很神奇的填坑法呢
 * https://leetcode.wang/leetCode-36-Valid-Sudoku.html
 */

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    bool rows[9][9] = {false};
    bool columns[9][9] = {false};
    bool boxes[3][3][9] = {false};

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;

        int target = board[i][j] - '1';

        if (rows[i][target]) return false;

        rows[i][target] = true;

        if (columns[j][target]) return false;

        columns[j][target] = true;

        if (boxes[i / 3][j / 3][target]) return false;

        boxes[i / 3][j / 3][target] = true;
      }
    }

    return true;
  }
} solution;

int main() {
  vector<vector<char>> board = {{'.', '8', '7', '6', '5', '4', '3', '2', '1'},
                                {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
                                {'9', '.', '.', '.', '.', '.', '.', '.', '.'}};

  cout << solution.isValidSudoku(board) << endl;

  return 0;
}