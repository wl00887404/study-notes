#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 跨向度大的會被刪去
 * 頭 一樣大 大 比尾還大
 * 尾 小 大
 */

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int length = intervals.size();
    if (length <= 1) return 0;

    sort(intervals.begin(), intervals.end());

    int result = 0;
    int i = 0;
    vector<int>* current = &intervals[0];

    for (int j = 1; j < length; j++) {
      if (intervals[i][1] <= intervals[j][0]) {
        i = j;
        continue;
      }

      result++;

      if (intervals[i][1] > intervals[j][1]) {
        i = j;
      }
    }

    return result;
  }

 private:
};