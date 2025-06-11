#include <iostream>
#include <vector>
using namespace std;

/**
 * 3356 來的，現在有了 diff array 的知識了
 * 這題改成給了 [l, r, value]
 * 問幾次操作之後，可以讓 nums 歸零
 */

class Solution {
 public:
  int size;
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    size = nums.size();
    int qSize = queries.size();
    vector<int> diff(size, 0);
    vector<int> totalDiff(size, 0);

    // 出生就是 0 陣列
    if (isZeroArray(nums, diff)) return 0;

    for (int k = 0; k < qSize; k++) {
      const vector<int>& q = queries[k];
      const int& begin = q[0];
      int end = q[1] + 1;
      const int& value = q[2];

      totalDiff[begin] += value;
      if (end < size) totalDiff[end] -= value;
    }

    // 提早知道不可能達成
    if (!isZeroArray(nums, totalDiff)) return -1;

    for (int k = 0; k < qSize; k++) {
      const vector<int>& q = queries[k];
      const int& begin = q[0];
      int end = q[1] + 1;
      const int& value = q[2];

      diff[begin] += value;
      if (end < size) diff[end] -= value;

      if (isZeroArray(nums, diff)) return k + 1;
    }

    return -1;
  }

  bool isZeroArray(vector<int>& nums, vector<int>& diff) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
      sum += diff[i];
      if (sum < nums[i]) return false;
    }

    return true;
  }
};