
/**
 * 2021/9/24 寫過
 */

/**
 * dp 題組 1-2
 * 太簡單了不知道有什麼好說的
 */

class Solution {
 public:
  int tribonacci(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
  }
};