#include <cassert>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 2023/9/18
 * FIXME: 未完成
 */

/**
 * 跟 123 一樣
 * 123 是可以進行 2 次交易
 * 188 是可以進行 k 次交易
 */

/**
 * 跟 123 同樣的想法的話，就切成 k 個區間
 * 假設三個區間 ， [0, i] [i, j] [j, n] 的最佳解
 * 能否快速的獲得兩點之間的最佳解？
 * 也就是某區間的最大值與最小值
 */

/**
 * 參考 https://hackmd.io/@wiwiho/cp-note/%2F%40wiwiho%2FCPN-segment-tree
 * 寫了一個 Segment Tree 暫停想一想，最低點與最高點可以產生最大利益
 * 一次交易就是兩點連線，而且斜率是正的
 * 只是要檢查這些線不能交錯
 */

/**
 * Segment Tree GG 啦
 * 可以快速抓出區間的最大值與最小值
 * 但是不能判斷前後，買股票一定是先買後賣
 *
 * 如果改一下 Segment Tree 的寫法
 * maxProfit = max(left->maxProfit, right->maxProfit, right->max - left->min)
 * 如果涵蓋兩個範圍的 query 要怎麼處理？
 *
 * 完全沒想法，先放棄 Segment Tree
 */

/**
 * 回到 123 的想法
 * 假設 size = 6
 * 123 的 k = 2 只要兩次交易
 * 只要求出 [0, 2] [0, 3] [0, 4]，還有 [2, 6] [3, 6] [4, 6] 的 maxProfit
 * k = 1 的只要求出 [0, 6] 的 maxProfit
 *
 * 如果 188 的情況，就有 k = 3
 * 那還需要 [0, 2] [2, 4] [4, 6] 的 maxProfit
 *
 * 由後往前的是一定會用到的，所以可以先求出來
 */

class Solution {
 public:
  int size;
  vector<pair<int, int>*> cache;
  vector<int>* pricesP;

  int maxProfit(int k, vector<int>& prices) {
    size = prices.size();
    pricesP = &prices;
    cache.resize(size * size, NULL);

    int result = 0;

    return result;
  }

  int helper(int k, int begin) {
    if (k == 1) return getMaxProfit(begin, size);

    int result = 0;
    for (int i = begin + 2; begin < size; i++) {
      int maxProfit = getMaxProfit(begin, i);
      result = max(result, maxProfit + helper(k - 1, i));
    }

    return 0;
  }

  int getMaxProfit(int i, int j) {
    int key = getKey(i, j);

    if (cache[key] != NULL) return cache[key]->second - cache[key]->first;

    return 0;
  }

  int getKey(const int& i, const int& j) { return i * size + j; }

  // [0, size] [1, size] [2, size] ... [size - 1, size]
  void initCache() {
    vector<int>& prices = *pricesP;
    int minimum = prices[size - 1];
    int maximum = prices[size - 1];

    for (int i = size - 1; i >= 0; i--) {
      minimum = min(minimum, prices[i]);
      maximum = max(maximum, prices[i]);

      int key = getKey(i, size - 1);
      cache[key] = new pair<int, int>(minimum, maximum);
    }
  }
};
