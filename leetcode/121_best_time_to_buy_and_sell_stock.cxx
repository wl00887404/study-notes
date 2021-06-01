#include <iostream>
#include <vector>
using namespace std;

/**
 * 簡單好理解的題目
 * 適合當面試題
 */

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int length = prices.size();
    if (length < 2) return 0;

    int min = prices[0];
    int revenue = 0;
    for (int i = 1; i < length; i++) {
      if (prices[i] < min) min = prices[i];
      int nextRevenue = prices[i] - min;
      if (nextRevenue > revenue) revenue = nextRevenue;
    }

    return revenue;
  }
};