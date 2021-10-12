#include <math.h>

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 如果血多負擔少，具有絕對優勢
 * 如果血多負擔多 or 血少負擔少要怎麼選
 * 血多負擔多 => 不會再更慘了
 * 血少負擔少 => 如果再來受傷不重會贏
 */

/**
 * 遇到我全到要的情況超麻煩
 * 想半天寫不出來
 */

/**
 * 2021/10/7 看解答啦
 * 從右下往前推血量比較好
 * 不會遇到惱人的選擇問題
 */

class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();
    int mLast = m - 1;
    int nLast = n - 1;

    vector<vector<int>> hps(m, std::vector<int>(n));
    // 右下角初使的血量 1 - 傷害
    // 如果是補血，那就血量要求就是 1
    hps[mLast][nLast] = max(1 - dungeon[mLast][nLast], 1);

    // 往左走
    int i = mLast;
    while (i--) {
      hps[i][nLast] = max(hps[i + 1][nLast] - dungeon[i][nLast], 1);
    }

    int j = nLast;
    while (j--) {
      hps[mLast][j] = max(hps[mLast][j + 1] - dungeon[mLast][j], 1);
    }

    if (m == 1 || n == 1) return hps[0][0];

    for (i = mLast - 1; 0 <= i; i--) {
      for (j = nLast - 1; 0 <= j; j--) {
        int fromBottom = max(hps[i][j + 1] - dungeon[i][j], 1);
        int fromRight = max(hps[i + 1][j] - dungeon[i][j], 1);
        hps[i][j] = min(fromBottom, fromRight);
      }
    }

    return hps[0][0];
  }
} solution;

int main() {
  vector<vector<int>> board = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};

  cout << solution.calculateMinimumHP(board) << endl;

  return 0;
}