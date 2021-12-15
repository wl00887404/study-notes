#include <iostream>
#include <vector>

using namespace std;

/**
 * 2021/12/15
 * 
 * 跟 Jason 討論過
 * 因為買賣次數無限
 * 能買就買、能賣就賣
 * 賠錢不要算
 * 就是最大利潤了
 */

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int result = 0;

    for (int i = 1; i < size; i++) {
      result += max(prices[i] - prices[i - 1], 0);
    }

    return result;
  }
};