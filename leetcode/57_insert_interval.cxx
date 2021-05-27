#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 敢不敢更快一點
 */

void logInterval(string label, vector<int>& interval) {
  cout << label << ": [" << interval[0] << ", " << interval[1] << "]" << endl;
}

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    int i = 0;
    bool isUsed = false;
    int length = intervals.size() + 1;
    vector<vector<int>> result;
    while (length--) {
      insertLast(result, getNextInterval(intervals, newInterval, i, isUsed));
    };

    return result;
  }

 private:
  void insertLast(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // logInterval("newInterval", newInterval);
    int length = intervals.size();
    if (intervals.size() == 0) return intervals.push_back(newInterval);

    vector<int>& lastIntervals = intervals[intervals.size() - 1];
    // logInterval("lastIntervals", lastIntervals);

    // 不相交（新頭在範圍外）
    if (lastIntervals[1] < newInterval[0]) {
      return intervals.push_back(newInterval);
    }
    // 包含（新尾在範圍內）
    if (newInterval[1] <= lastIntervals[1]) return;
    // 相交（新尾在範圍外）
    lastIntervals[1] = newInterval[1];
  }
  vector<int>& getNextInterval(vector<vector<int>>& intervals,
                               vector<int>& newInterval, int& i, bool& isUsed) {
    if ((i != intervals.size() && intervals[i][0] < newInterval[0]) || isUsed) {
      return intervals[i++];
    }

    isUsed = true;
    return newInterval;
  }
} solution;

int main() {
  vector<vector<int>> intervals = {{1, 3}, {6, 9}};
  vector<int> newInterval = {2, 5};
  // vector<vector<int>> intervals = {{1, 5}};
  // vector<int> newInterval = {2, 3};

  solution.insert(intervals, newInterval);
  return 0;
}