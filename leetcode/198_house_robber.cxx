#include <iostream>
#include <vector>
using namespace std;

/**
 * 選就 + 2
 * 不選就 + 1
 * 有個 cache 記下結果
 */

class Solution {
 public:
  int rob(vector<int>& nums) {
    int length = nums.size();
    int cache[length];
    for (int i = 0; i < length; i++) cache[i] = -1;

    return rob(nums, cache, 0, length);
  }

  int rob(vector<int>& nums, int* cache, int i, int& length) {
    if (i >= length) return 0;
    if (cache[i] != -1) return cache[i];

    int selectedResult = nums[i] + rob(nums, cache, i + 2, length);
    int notSelectedResult = rob(nums, cache, i + 1, length);

    cache[i] = max(selectedResult, notSelectedResult);

    return cache[i];
  }
};