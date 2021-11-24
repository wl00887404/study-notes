#include <iostream>
#include <vector>

using namespace std;

/**
 * 這題就跟 96 一樣很簡單嘛
 * BST 就 node -> left 、 node 、 node -> right
 *
 * 1 => 1
 * 2 => n -> 1 | 1 <- n
 * 3 => n -> 2 | 1 <- n -> 1 | 2 <- n
 * 4 => n -> 3 | 1 <- n -> 2 | 2 <- n -> 1 | 3 <- n
 */

class Solution {
 public:
  int numTrees(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      dp[i] = 0;
      for (int j = 0; j < i; j++) {
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }

    return dp[n];
  }
} solution;

int main() {
  cout << solution.numTrees(4) << endl;
  return 0;
}