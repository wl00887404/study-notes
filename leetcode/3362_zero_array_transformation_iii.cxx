#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 每日一題偷抄作業，下次補
 */

/**
 * 3355, 3356 來的，我已經有了 diff array 的記憶
 *
 * 這題改成可以移除 queries，用最少的 query 完成
 */

/**
 * 要 BFS
 *
 * 0000
 * 1000, 0100, 0010, 0001
 * 1100
 *
 * 0000
 * 0001
 * 0010
 * 0011
 * 0100
 * 0101
 *
 */

class Solution {
 public:
  int size;
  int qSize;
  vector<int> diff;
  vector<int>* numsP;
  vector<vector<int>>* queriesP;

  int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    numsP = &nums;
    size = nums.size();
    qSize = queries.size();
    queriesP = &queries;
    diff.resize(size, 0);

    for (int k = 0; k < qSize; k++) {
      const vector<int>& q = queries[k];
      const int& begin = q[0];
      int end = q[1] + 1;

      diff[begin]++;
      if (end < size) diff[end]--;
    }

    // 提早知道不可能達成a
    if (!isZeroArray()) return -1;

    for (int i = 0; i < size; i++) {
      diff[i] = 0;
    }

    return qSize - helper(0, 0);
  }

  int helper(int i, int result) {
    if (i == qSize) {
      if (!isZeroArray()) return -1;

      return result;
    }

    // 不選
    int notChosenResult = helper(i + 1, result);
    // 不選優先，找到解啦！
    if (notChosenResult != -1) return notChosenResult;

    // 選
    vector<vector<int>>& queries = *queriesP;
    const vector<int>& q = queries[i];
    const int& begin = q[0];
    int end = q[1] + 1;

    diff[begin]++;
    if (end < size) diff[end]--;

    int chosenResult = helper(i + 1, result + 1);

    // undo 選
    diff[begin]--;
    if (end < size) diff[end]++;

    return chosenResult;
  }

  bool isZeroArray() {
    vector<int>& nums = *numsP;
    int sum = 0;

    for (int i = 0; i < size; i++) {
      sum += diff[i];
      if (sum < nums[i]) return false;
    }

    return true;
  }
};