#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 過了是過了
 * 不過慢到射
 */

/**
 * 懷疑是 unordered_map 太慢了
 * 改成紀錄 stockIndex 快了一點
 *   1636ms -> 276ms
 *
 * 估計 i 、 stockIndex 一直在換
 * 導致速度太慢
 */

/**
 * 2021/10/20
 *
 * 最佳解的解釋在這裡：
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
 *
 * 太神啦
 */

class RecursiveSolution {
 public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();

    int cache[size * (size + 1)];
    for (int i = 0; i < size * (size + 1); i++) cache[i] = 0;

    return maxProfit(cache, prices, size);
  }
  int maxProfit(int* cache, vector<int>& prices, int& size, int i = 0,
                int stockIndex = -1) {
    if (i >= size) return 0;
    if (cache[i * size + stockIndex + 1]) {
      return cache[i * size + stockIndex + 1];
    }

    int& price = prices[i];
    int maybeBuyOrSell = 0;
    if (stockIndex == -1) {
      // 如果沒有存貨就可以買
      maybeBuyOrSell = maxProfit(cache, prices, size, i + 1, i);
    } else if (prices[stockIndex] < price) {
      // 如果有存貨就可以賣
      // 賣了就不能馬上買要冷卻
      maybeBuyOrSell = price - prices[stockIndex] +
                       maxProfit(cache, prices, size, i + 2, -1);
    }

    int maybeCooldown = maxProfit(cache, prices, size, i + 1, stockIndex);

    int result = max(maybeBuyOrSell, maybeCooldown);
    cache[i * size + stockIndex + 1] = result;

    return result;
  }
} solution;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int s0[n], s1[n], s2[n];
    s0[0] = 0;
    s1[0] = -prices[0];
    s2[0] = -1;
    for (int i = 1; i < n; i++) {
      s0[i] = max(s0[i - 1], s2[i - 1]);
      s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
      s2[i] = s1[i - 1] + prices[i];
    }
    return max(s0[n - 1], s2[n - 1]);
  }
};

int main() {
  vector<int> prices = {
      70, 4,  83, 56, 94, 72, 78, 43, 2,  86, 65, 100, 94, 56, 41, 66,
      3,  33, 10, 3,  45, 94, 15, 12, 78, 60, 58, 0,   58, 15, 21, 7,
  };

  solution.maxProfit(prices);
  return 0;
}