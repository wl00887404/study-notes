#include <iostream>
#include <vector>

using namespace std;

/**
 * 一樣可以走或是跳
 * 只是每一格都有 cost
 * 要到終點最好 cost
 */

class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();

    if (size == 1) return cost[0];
    cost.push_back(0);

    for (int i = 2; i <= size; i++) {
      cost[i] += min(cost[i - 1], cost[i - 2]);
    }

    return cost[size];
  }
};