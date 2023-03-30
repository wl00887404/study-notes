#include <iostream>
#include <vector>

using namespace std;

/**
 * 最簡單的做法就是全買
 * 看能夠一口氣可以度過幾天
 * 然後記住每一個的最佳情境
 */

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    size = days.size();
    daysPointer = &days;
    costsPointer = &costs;
    vector<int> cache(size, -1);
    cachePointer = &cache;

    return helper(0);
  }

  int size;
  vector<int>* daysPointer;
  vector<int>* costsPointer;
  vector<int>* cachePointer;

  int helper(int i) {
    if (i >= size) return 0;
    vector<int>& cache = *cachePointer;
    if (cache[i] != -1) return cache[i];

    vector<int>& days = *daysPointer;
    vector<int>& costs = *costsPointer;

    // 買當天票
    // cout << "計算 " << i << " 買當日票的結果" << endl;
    cache[i] = costs[0] + helper(i + 1);
    // cout << i << " 買當日票的結果為 " << cache[i] << endl;

    // 買七天票
    int afterSeven = days[i] + 7;
    int nextI = i;
    // cout << "計算 " << i << " 買七日票的結果" << endl;
    while (nextI < size && days[nextI] < afterSeven) nextI++;
    // cout << i << " 買七日票可以跳到 day[" << nextI << "]" << endl;
    cache[i] = min(cache[i], costs[1] + helper(nextI));
    // cout << i << " 買七日票的結果為 " << (costs[1] + helper(nextI)) << endl;

    // 買三十天票
    int afterThirty = days[i] + 30;
    // cout << "計算 " << i << " 買三十日票的結果" << endl;
    while (nextI < size && days[nextI] < afterThirty) nextI++;
    // cout << i << " 買三十日票可以跳到 day[" << nextI << "]" << endl;
    cache[i] = min(cache[i], costs[2] + helper(nextI));
    // cout << i << " 買三十日票的結果為 " << (costs[2] + helper(nextI)) <<
    // endl;

    return cache[i];
  }
};