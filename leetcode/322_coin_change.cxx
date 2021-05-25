#include <iostream>
#include <vector>
using namespace std;

// your code here

/**
 * 貪婪是行不通的 :(
 * 而且會有單顆為最佳解的情況（不能用除的）
 * 43 [17, 13, 1] => [1, 2, 0] 而非 [2, 0, 9] | [0, 3, 4]
 * 66 [23, 17, 13, 1] => [1, 1, 2, 0]
 *
 * 分成 60 [13, 1] 與 43 [17, 13, 1]
 */

/**
 * Time Limit Exceeded 的重點是 BFS
 * 不應該用 DFS
 *
 * 60 [17, 10, 5]
 * 1 枚硬幣 => [43, 50, 45]
 * 2 枚硬幣 => [26, 33, 28] [33, 40, 35] [38, 45, 40]
 *   33 重複 (17 * 1 + 10 * 1 與 10 * 1 + 17 * 1)
 *   40 重複 (10* 1 與 5 * 2)
 */

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;

    bool isExecuted[amount + 1];
    for (int i = 0; i < amount; i++) isExecuted[i + 1] = false;
    isExecuted[amount] = true;

    vector<int> currentAmounts = {amount};

    int i = 0;
    int length = 1;
    while (length != 0) {
      i++;
      int lastIndex = currentAmounts.size() - 1;
      int nextLength = 0;
      for (int j = 0; j < length; j++) {
        int currentAmount = currentAmounts[lastIndex - j];
        for (int k = 0; k < coins.size(); k++) {
          int nextAmount = currentAmount - coins[k];
          if (nextAmount == 0) return i;
          if (nextAmount < 0 || isExecuted[nextAmount]) continue;
          isExecuted[nextAmount] = true;
          currentAmounts.push_back(nextAmount);
          nextLength++;
        }
      }

      length = nextLength;
    }

    return -1;
  }
} solution;

int main() {
  // vector<int> coins = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
  // int amount = 9999;
  vector<int> coins = {1, 2, 5};
  int amount = 11;

  cout << solution.coinChange(coins, amount) << endl;
  return 0;
}
