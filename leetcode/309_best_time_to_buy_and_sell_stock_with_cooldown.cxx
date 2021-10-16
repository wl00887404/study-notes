#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 過了是過了
 * 不過慢到射
 *
 * TODO: 研究最佳解
 */

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();

    unordered_map<int, int> cache[size];

    return maxProfit(cache, prices, size);
  }
  int maxProfit(unordered_map<int, int>* cache, vector<int>& prices, int& size,
                int i = 0, int stock = -1) {
    if (i >= size) return 0;
    if (cache[i].count(stock)) return cache[i][stock];

    int& price = prices[i];
    int maybeBuyOrSell = 0;
    if (stock == -1) {
      // 如果沒有存貨就可以買
      maybeBuyOrSell = maxProfit(cache, prices, size, i + 1, price);
    } else if (stock < price) {
      // 如果有存貨就可以賣
      // 賣了就不能馬上買要冷卻
      maybeBuyOrSell =
          price - stock + maxProfit(cache, prices, size, i + 2, -1);
    }

    int maybeCooldown = maxProfit(cache, prices, size, i + 1, stock);

    int result = max(maybeBuyOrSell, maybeCooldown);
    cache[i][stock] = result;

    return result;
  }
} solution;

int main() {
  vector<int> prices = {
      70, 4,  83, 56, 94, 72, 78, 43, 2,  86, 65, 100, 94, 56, 41, 66,
      3,  33, 10, 3,  45, 94, 15, 12, 78, 60, 58, 0,   58, 15, 21, 7,
  };

  solution.maxProfit(prices);
  return 0;
}