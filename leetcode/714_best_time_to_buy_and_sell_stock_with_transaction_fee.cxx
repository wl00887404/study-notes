#include <iostream>
#include <vector>

using namespace std;

class MyDpSolutionSolution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    size = prices.size();
    pricesP = &prices;
    this->fee = fee;
    cache.resize(size, -1);

    return helper(0);
  }

  vector<int>* pricesP;
  int size;
  int fee;
  vector<int> cache;

  int helper(int i) {
    if (i >= size) return 0;
    if (cache[i] != -1) return cache[i];
    vector<int>& prices = *pricesP;

    cache[i] = 0;
    // i 天買，j 天賣
    for (int j = i + 1; j < size; j++) {
      if (prices[j] < prices[i]) {
        // 前面都不賣
        // 在 j 遇到更低的價格，那還不如在 j 買就好
        cache[i] = max(cache[i], helper(j));
        break;
      }
      // 賣了也沒錢賺
      if (prices[j] <= prices[i] + fee) continue;
      // 在 j 賣出的結果
      cache[i] = max(cache[i], prices[j] - prices[i] - fee + helper(j + 1));
    }

    return cache[i];
  }
};

/**
 * 重新想想
 * 假設我在 i 天往後看
 * 遇到比 i 高的 => 準備賣
 * 遇到比 i 低的 => 賣掉前面最高，買這個
 */

/**
 * 這樣不行，因為假設沒有遇到比較低的價格
 * 不知道在哪個高點賣會比較好
 */

/**
 * 參考 309 的 state machine 的想法
 * s0 空狀態，來源是什麼都不做，或是從 s2 賣掉過來
 * s1 是持有，來源是什麼都不做，或是從 s0 買進
 * s2 是剛賣掉，來源只有從 s1 賣掉後
 *
 * s0[i] = max(s0[i - 1], s2[i - 1])
 * s1[i] = max(s1[i - 1], s0[i - 1] - prices[i])
 * s2[i] = s1[i - 1] + prices[i]
 *
 * 這題有需要 s2 嗎？
 * s0 是空狀態，來源是什麼都不做，或是從 s1 賣掉過來
 * s1 是持有狀態，來源是什麼都不做，或是從 s0 買進
 */

class StateMachineSolution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int size = prices.size();
    vector<int> s0(size);
    vector<int> s1(size);

    s0[0] = 0;
    s1[0] = -1 * prices[0];

    for (int i = 1; i < size; i++) {
      s0[i] = max(s0[i - 1], s1[i - 1] + prices[i] - fee);
      s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
    }

    return s0[size - 1];
  }
};

class Solution : public MyDpSolutionSolution {
 public:
  Solution() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
};