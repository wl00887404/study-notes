#include <iostream>
using namespace std;

/**
 * 2025/4/25
 * FIXME: 未完成
 */

/**
 *  理想陣列 => array[i + 1] % array[i] == 0
 *  假設 array[i] = x, x * y < maxValue, y = 1 ~ maxValue / x
 */

/**
 * 實際考慮不同數字的組合
 * 但當 maxValue = 5 時，[3, _] [4, _] [5, _] 會是同樣的結果
 * 共通點是 5 / 3 == 5 / 4 == 5 / 5
 * 所以用除的會比較快
 */
class TimeLimitExceededSolution1 {
 public:
  int n;
  int maxValue;
  unordered_map<int, unsigned int> cache;

  int idealArrays(int n, int maxValue) {
    this->n = n;
    this->maxValue = maxValue;

    return helper(1, n);
  }

  int helper(int x, int length) {
    int key = getKey(x, length);

    if (cache.count(key)) return cache[key];

    int scale = maxValue / x;  // 可以乘數可以是 1 ~ scale（包含 scale）

    if (length == 1) {
      cache[key] = scale;
      return cache[key];
    }

    cache[key] = 0;
    for (int y = 1; y <= scale; y++) {
      // [x * y, _] 開頭
      cache[key] = (cache[key] + helper(x * y, length - 1)) % 1000000007;
    }

    return cache[key];
  }

  int getKey(int x, int length) { return x * n + length; }
};

/**
 * [_, _, _, _, _] => (5, 3)
 * [1, _, _, _, _] => (4, 3)
 * [1, 1, _, _, _] => (3, 3)
 * [1, 1, 1, _, _] => (2, 3)
 * [1, 1, 1, 1, _] => (1, 3) => 3 => return
 * [1, 1, 1, 2, _] => (1, 1) => 1 => return
 * [1, 1, 1, 3, _] => (1, 1) => 1 => return
 * [1, 1, 2, _, _] => (2, 1) => 1 => return
 * [1, 1, 3, _, _] => (2, 1) => 1 => return
 * [1, 2, _, _, _] => (3, 1) => 1 => return
 * [1, 3, _, _, _] => (3, 1) => 1 => return
 * [2, _, _, _, _] => (4, 1) => 1 => return
 * [3, _, _, _, _] => (4, 1) => 1 => return
 */
class TimeLimitExceededSolution2 {
 public:
  int maxN;
  unordered_map<int, unsigned int> cache;

  int idealArrays(int n, int maxValue) {
    this->maxN = n;
    return helperWithCache(n, maxValue);
  }

  int helper(int n, int maxValue) {
    // 假設 n = 1, maxValue = 5
    // 那可以有 [1] [2] [3] [4] [5] 的陣列
    if (n == 1) return maxValue;

    // 假設 n = 2, maxValue = 1
    // 結果只會有 [1, 1]
    if (maxValue == 1) return 1;

    unsigned int result = 0;
    for (int i = 1; i <= maxValue; i++) {
      result = (result + helperWithCache(n - 1, maxValue / i)) % 1000000007;
    }

    return result;
  }

  int helperWithCache(int n, int maxValue) {
    int key = getKey(n, maxValue);
    if (cache.count(key)) return cache[key];

    cache[key] = helper(n, maxValue);

    return cache[key];
  }

  int getKey(int n, int maxValue) { return maxValue * maxN + n; }
};

/**
 * 懷疑是 unordered_map 效能不好，結果還是沒過 QQ
 */
class TimeLimitExceededSolution3 {
 public:
  int idealArrays(int n, int maxValue) {
    // n = 1 ~ n
    // maxValue = 1 ~ maxValue
    // dp[0][0] =>> n = 1, maxValue =1
    vector<vector<unsigned int> > dp(n + 1,
                                     vector<unsigned int>(maxValue + 1, 0));

    for (int j = 1; j <= maxValue; j++) {
      // 假設 n = 1, maxValue = 5
      // 那可以有 [1] [2] [3] [4] [5] 的陣列
      dp[1][j] = j;
    }

    for (int i = 1; i <= n; i++) {
      // 假設 n = 2, maxValue = 1
      // 結果只會有 [1, 1]
      dp[i][1] = 1;
    }

    /**
     * dp(n, maxValue)
     * = dp(n - 1, maxValue / 1) +
     *   dp(n - 1, maxValue / 2) + ... +
     *   dp(n - 1, maxValue / maxValue)
     */
    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= maxValue; j++) {
        for (int k = 1; k <= j; k++) {
          dp[i][j] = (dp[i][j] + dp[i - 1][j / k]) % 1000000007;
        }
      }
    }

    return dp[n][maxValue];
  }
};

/**
 * 換個思路把他當排列組合寫
 * 開頭是 k，後面能有的選項是 k * (1, ~ (maxValue) / k)
 * 假設 n = 4, k = 2, maxValue = 9
 * 選項有 2, 4, 6, 8 順序一定是由小到大，所以只要決定每個項有幾個就好
 * n = 4 => (4) (1, 3) (2, 2) (1, 1, 2)
 * n = 5 => (5) (1, 4) (2, 3) (1, 1, 3) (1, 2, 3)
 *
 *
 *
 */
