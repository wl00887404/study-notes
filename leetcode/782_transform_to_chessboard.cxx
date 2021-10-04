#include <math.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 列舉結果放在
 * https://codepen.io/wl00887404/pen/oNwQBzv?editors=0010
 */

/**
 * 同一個方向一直換只會重複
 * 一定要交織（直橫直橫）才能產生新組合
 */

/**
 * 不可能列舉慢慢上去
 * n = 8 要跑個 3 分鐘
 * 好好想怎麼交換吧
 *
 * n 是奇數
 * 有多的那個一定要在兩頭
 *
 * n 是偶數
 * 以一個為頭就好
 */

/**
 * 要是有兩組以上可以交換
 * 對最短路徑會不會有影響？
 *
 * 圖形都是對稱的
 * 所以不會有影響
 */

void debug(vector<vector<int>> board, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

class Solution {
 public:
  int movesToChessboard(vector<vector<int>>& board) {
    int n = board.size();

    int result1 = tryToFix(board, n);
    if (result1 == -1) return -1;

    flip(board, n);

    int result2 = tryToFix(board, n);
    if (result2 == -1) return -1;

    if (!isValid(board, n)) return -1;

    return result1 + result2;
  }

  bool isValid(vector<vector<int>>& board, int& n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != 0 && board[i][j] == board[i - 1][j]) return false;
        if (j != 0 && board[i][j] == board[i][j - 1]) return false;
      }
    }

    return true;
  }

  int tryToFix(vector<vector<int>>& board, int& n) {
    int expectedChess = getCorrectStartChess(board, n);
    queue<int> blackQueue;
    queue<int> whiteQueue;

    for (int i = 0; i < n; i++) {
      if (board[i][0] != expectedChess) {
        queue<int>& queue = expectedChess == 1 ? blackQueue : whiteQueue;
        queue.push(i);
      }

      expectedChess = !expectedChess;
    }

    int result = blackQueue.size();
    if (result != whiteQueue.size()) return -1;

    while (!blackQueue.empty() && !whiteQueue.empty()) {
      int& i = blackQueue.front();
      int& j = whiteQueue.front();

      board[i].swap(board[j]);

      blackQueue.pop();
      whiteQueue.pop();
    }

    return result;
  }

  void flip(vector<vector<int>>& board, int& n) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int temp = board[i][j];
        board[i][j] = board[j][i];
        board[j][i] = temp;
      }
    }
  }

  bool getCorrectStartChess(vector<vector<int>>& board, int& n) {
    // 偶數的話要選錯的少的那個顏色
    if (n % 2 == 0) {
      int& firstChess = board[0][0];
      int expectedChess = !firstChess;
      int wrongCount = 0;
      for (int i = 1; i < n; i++) {
        if (board[i][0] != expectedChess) {
          wrongCount++;
        }
        expectedChess = !expectedChess;
      }

      return wrongCount * 2 > n ? !firstChess : firstChess;
    }

    // 奇數要選多出來的那個顏色
    int result = 0;

    for (int i = 0; i < n; i++) {
      int& chess = board[i][0];

      // 因為只要取差
      // 黑就加 1 白就減 1
      result += chess ? 1 : -1;
    }

    // 黑白棋差不是 1 或 -1
    return result == 1;
  }

} solution;

int main() {
  vector<vector<int>> board = {{0, 0, 1, 0, 1, 1}, {1, 1, 0, 1, 0, 0},
                               {1, 1, 0, 1, 0, 0}, {0, 0, 1, 0, 1, 1},
                               {1, 1, 0, 1, 0, 0}, {0, 0, 1, 0, 1, 1}};

  cout << solution.movesToChessboard(board) << endl;

  return 0;
}