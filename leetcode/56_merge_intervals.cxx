#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    int from = intervals[0][0];  // 入口
    int fromLimit = from;

    int portals[10001];
    for (int i = 0; i < 10001; i++) portals[i] = -1;

    for (vector<int>& internal : intervals) {
      // 如果傳送點重複，取大的
      if (portals[internal[0]] < internal[1]) {
        portals[internal[0]] = internal[1];
      }
      if (internal[0] < from) from = internal[0];
      if (internal[0] > fromLimit) fromLimit = internal[0];
    }

    while (from <= fromLimit) {
      if (portals[from] == -1) {
        from++;
      } else {
        int to = travel(portals, from);
        result.push_back({from, to});
        from = to + 1;
      }
    }

    return result;
  }

 private:
  int travel(int* portals, int& from) {
    int to = portals[from];
    if (to == -1) throw "傳送門故障";

    int now = from;

    while (now != to) {
      now++;

      // 找到的傳送門可以到更遠的地方！
      if (portals[now] > to) to = portals[now];
    }

    return to;
  }
} solution;

class SortSolution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int length = intervals.size();
    if (length <= 1) return intervals;

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    for (int i = 0; i < length; i++) {
      if (result.empty() || result.back()[1] < intervals[i][0]) {
        result.push_back(intervals[i]);
        continue;
      }

      if (result.back()[1] < intervals[i][1]) {
        result.back()[1] = intervals[i][1];
      }
    }

    return result;
  }
};

int main() {
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

  solution.merge(intervals);
  return 0;
}