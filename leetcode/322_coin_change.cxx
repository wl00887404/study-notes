#include <iostream>
#include <limits>
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

class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    int cache[amount + 1];
    for (int i = 1; i <= amount; i++) cache[i] = 0;

    return coinChange(cache, coins, amount, 0);
  }

  int coinChange(int* cache, vector<int>& coins, int amount, int i) {
    if (amount == 0) return 0;

    if (i == coins.size() - 1) {
      return amount % coins[i] == 0 ? amount / coins[i] : -1;
    }

    int countWithoutCoin = coinChange(cache, coins, amount, i + 1);

    if (amount < coins[i]) return countWithoutCoin;
    int countWithCoin = coinChange(cache, coins, amount - coins[i], i);
    if (countWithCoin == -1) return countWithoutCoin;

    countWithCoin++;
    if (countWithoutCoin == -1) return countWithCoin;

    return min(countWithCoin, countWithoutCoin);
  }
} solution;

int main() {
  vector<int> coins{1, 2, 5};
  int amount = 11;

  // vector<int> coins{1, 3, 5};
  // int amount = 4;

  cout << solution.coinChange(coins, amount) << endl;
  return 0;
}