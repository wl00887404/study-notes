#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 怎麼是個排列組合題
 * n 個糖果，分給 3 個小孩，每個人最多拿到 limit 個
 * i = 0 ~ limit
 * j = i ~ limit
 * k = n - i - j
 *
 * n = 5
 *
 * 由小到大，就不會重複
 *
 * 0 0 5, 5 超過 limit
 * 0 1 4, 4 超過 limit
 * 0 2 3, 3 超過 limit
 * 0 3 2, j > k 重複組合
 *
 * 1 1 3, 3 超過 limit
 * 1 2 2, 找到一組了
 * 1 3 1, j > k 重複組合
 *
 * 2 2 1, j > k 重複組合
 * 3 3 -1, j > k 重複組合
 *
 * x, x, n - 2x
 * 其中 n - 2x >= x
 * => n >= 3x
 * => n / 3 >= x
 *
 * 1 2 2 要怎麼排序
 * 3 個不一樣就是 3! = 6
 * 2 個一樣 1 個不一樣就是 3! / 2! = 3
 * 3 個都一樣就是 3! / 3!
 */

/**
 * 直接進入數學時間！
 * 三個不同、兩個不同、三個相同
 * 三個相同 = n % 3 => n / 3, n / 3, n /3
 * 兩個不同 => x, x, n - 2x
 *   => (0, n), (1, n - 2), ..., (n / 2, 0)
 *   => 其中 0 <= x <= limit && 0 <= x <= n / 2 && 0 <=
 *   n - 2x <= limit => n - limit <= 2x => (n - limit) / 2  <= x
 * 三個不同 => x, y, 5 - x - y，避免重複，其中 x < y < n - x - y
 */

/**
 * FIXME: 應該有一個 O(n) 解
 */

class TleSolution {
 public:
  long long distributeCandies(int n, int limit) {
    long long result = 0;

    for (int i = 0; i <= limit; i++) {
      for (int j = i; j <= limit; j++) {
        int k = n - i - j;

        if (k > limit) continue;
        if (j > k) continue;

        result += p(i, j, k);
      }
    }

    return result;
  }

  int p(int i, int j, int k) {
    if (i == j && j == k) return 1;
    if (i == j || j == k) return 3;
    return 6;
  }
};

class Solution {
 public:
  long long distributeCandies(int n, int limit) {
    return all(n, limit) + pair(n, limit) + different(n, limit);
  }

  // 三個相同
  long long all(int n, int limit) {
    if (n % 3 != 0) return 0;
    if (n / 3 > limit) return 0;

    // 可以整除就有三個相同，而且這個值必須 <= limit
    return 1;
  }

  // 兩個相同
  long long pair(int n, int limit) {
    // 0 <= x <= limit
    // 0 <= x <= n
    // 0 <= n - 2x <= limit => (n - limit) / 2 <= x <= n / 2

    int lowerBound = max((n - limit) / 2 + (n - limit) % 2, 0);
    int upperBound = min(limit, n / 2);

    if (lowerBound > upperBound) return 0;

    long long result = upperBound - lowerBound + 1;
    if (n % 3 == 0 && n / 3 <= limit) result--;  // 扣除掉三個相同的結果
    result *= 3;

    return result;
  }

  long long different(int n, int limit) {
    // 固定 x，決定 y
    // 0 <= x <= limit
    // x < y <= limit
    // x < y < n - x - y <= limit => x < y < (n - x) / 2
    //   => n - x - limit <= y

    long long result = 0;
    for (int x = 0; x <= limit; x++) {
      int lowerBound = max(x + 1, n - x - limit);
      /**
       * x  y  z
       * 0  1 99
       * 0  2 98
       * ...
       * 0 49 51 最多到 49
       *
       * 1  2 97
       * 1  3 96
       * ...
       * 1 49 50 最多到 49
       */
      int upperBound = min((n - x) / 2 + (n - x) % 2 - 1, limit);

      if (lowerBound > upperBound) continue;

      result += (long long)(upperBound - lowerBound + 1) * 6;
    }

    return result;
  }
};