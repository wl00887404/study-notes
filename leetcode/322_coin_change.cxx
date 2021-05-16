#include <iostream>
#include <limits>
#include <unordered_set>
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
 */

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    unordered_set<int> currentAmounts = {amount};
    int i = 0;

    while (currentAmounts.size() != 0) {
      i++;

      unordered_set<int> nextAmounts = {};
      for (int currentAmount : currentAmounts) {
        for (int j = 0; j < coins.size(); j++) {
          int nextAmount = currentAmount - coins[j];
          if (nextAmount == 0) return i;
          if (nextAmount > 0 && !currentAmounts.count(nextAmount)) {
            nextAmounts.insert(nextAmount);
          }
        }
      }
      currentAmounts = nextAmounts;
    }

    return -1;
  }
} solution;

int main() {
  vector<int> coins = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
  int amount = 9999;

  cout << solution.coinChange(coins, amount) << endl;
  return 0;
}
