
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
/**
 * 升天電梯！升天電梯！電鰻 ...
 *
 * 人從左下角開始走，也就是 board[n - 1][0]
 * 一次可以走 1 ~ 6 步，最多走到 n ** 2
 * 如果該點有電梯或蛇，直接強制搭乘
 * 如果搭完電梯或蛇之後，又遇到電梯或蛇，這時候不能再次搭乘
 *
 * 根據 Example 1，格子是一來一回的
 * 1 在 [n - 1][0]，6 在 [n - 1][n - 1]
 * 7 在 [n - 2][n - 1]，12 在 [n - 2][0]
 */

/**
 * 寫好的轉換 function，可以把 board 當成線性的 array 處理
 * 再來決策，能執 6 點一定是 6 點的
 * 遇到梯子 => 上去、避開 =>  避開可能遇到更好的梯子嗎？
 * 遇到蛇 => 往回、避開 => 往回有機會遇到梯子嗎？
 */

/**
 * 還有一個情境，要是下個 6 步是 -1, 11, 12, 13, 14, 15
 * 會導致至多走到 -1，其他的點數必定傳送
 */

 /**
  * FIXME:
  * 
  * 這個 testcase 過不了
  * [
  *   [-1, -1, -1, -1, 48,  5, -1],
  *   [12, 29, 13,  9, -1,  2, 32],
  *   [-1, -1, 21,  7, -1, 12, 49],
  *   [42, 37, 21, 40, -1, 22, 12],
  *   [42, -1,  2, -1, -1, -1,  6],
  *   [39, -1, 35, -1, -1, 39, -1],
  *   [-1, 36, -1, -1, -1, -1,  5]
  * ]
  * 
  * 最短的路線是
  * 1. 1 => 2 傳送到 36
  * 2. 36 => 41 傳送到 29
  * 3. 29 => 35 傳送到 49
  * 但是我會先走
  * 1. 1 => 6
  * 2. 6 => 12 傳送到 35
  * 
  * 導致 35 的最短路徑是 2，無法從 29 踩上
  * 
  * 跳躍到某個點，跟走上某個點，這兩個情境應該要分開來
  */

class Solution {
 public:
  int n;
  vector<vector<int>>* boardP;
  vector<int> steps;  // 走到這裡最少的擲色次數
  int snakesAndLadders(vector<vector<int>>& board) {
    boardP = &board;
    n = board.size();
    // 可以走的格子是 0 ~ (n * n - 1)
    steps.resize(n * n, 401);

    helper(0, 0);

    for (int i = 0; i < n * n; i++) {
      cout << i+1 << ": " << steps[i] << endl;
    }

    return steps[n * n - 1] == 401 ? -1 : steps[n * n - 1];
  }

  void helper(int current, int turn) {
    // 被傳送到某節點
    // 已經被捷足先登了
    if (steps[current] < turn) return;

    steps[current] = turn;  // 登入！
    turn++;                 // 開始往前走
    for (int i = 6; i > 0; i--) {
      // 走出界了
      if (current + i >= n * n) continue;
      // 已經被捷足先登了

      if (steps[current + i] < turn) continue;

      int destination = get(current + i);

      // 只是個普通的格子，可以走走看
      if (destination == -1) {
        helper(current + i, turn);
        continue;
      }

      // 遇到電梯或是電鰻，強制傳送
      steps[current + i] = turn;  // 我走過這裡了，不確定有沒有必要
      helper(destination - 1, turn);
    }
  }
  // 0 ~ n ** 2 - 1
  int get(int index) {
    vector<vector<int>>& board = *boardP;
    int row = index / n;

    // row = 0, 2, 4... 是左到右
    if (row % 2 == 0) {
      return board[(n - 1) - row][(index % n)];
    }

    return board[(n - 1) - row][(n - 1) - (index % n)];
  }
};
