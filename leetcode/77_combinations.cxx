#include <iostream>
#include <vector>

using namespace std;

/**
 * 這題就是 C 幾選幾，列出所有的組合
 */

class Solution {
 public:
  // 範圍 [1, n] ， 一個組合 k 個數字
  vector<vector<int>> combine(int n, int k) {
    this->n = n;

    helper(1, k);

    return results;
  }

  void helper(int i, int k) {
    if (k == 1) {
      for (; i <= n; i++) {
        result.push_back(i);
        results.push_back(result);
        result.pop_back();
      }
      return;
    }

    // 假設 i = 1, k = 2, n = 4
    // 組合可以是 [1, ...] [2, ...] [3, 4]
    // 要跑過 1, 2, 3
    for (; i <= n - k + 1; i++) {
      result.push_back(i);
      helper(i + 1, k - 1);
      result.pop_back();
    }
  }

  vector<vector<int>> results;
  vector<int> result;
  int n;
};

/**
 * 上面的方法比較慢一點
 * C(n, k) 表示 [1, n] 取 k 的組合
 * C(5, 3) 舉例
 * 就是 [5, ...C(4, 2)] + [4, ...C(3, 2)] + [3, ...C(2, 2)]
 * C(4, 2) = [4, ...C(3, 1)] + [3, ...C(2, 1)] + [2, ...C(1, 1)]
 * C(3, 2) = [3, ...C(2, 1)] + [2, ...C(1, 1)]
 * 所以說 C(4, 2) = [4, ...C(3, 1)] + C(3, 2)
 * C(5, 3) = [5, ...C(4, 2)] + C(4, 3)
 */