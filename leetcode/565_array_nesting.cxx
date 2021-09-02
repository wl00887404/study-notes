// #include <math.h>

#include <iostream>
#include <vector>
using namespace std;

/**
 * value 為 0 ~ n - 1 而且不會重複
 * [5, 4, 0, 3, 1, 6, 2] 的例子會組成單鍊
 * 0 > 5 > 6 > 2
 * 1 > 4
 *
 * 一定會循環嗎？
 *
 * [1, 2, 3, 1] 不可能
 *
 */

class Solution {
 public:
  int arrayNesting(vector<int>& nums) {
    int result = 1;
    int length = nums.size();
    bool isVisited[length];
    for (int i = 0; i < length; i++) isVisited[i] = false;

    for (int i = 0; i < length; i++) {
      if (isVisited[i]) continue;

      result = max(result, helper(nums, isVisited, i));
    }

    return result;
  }

  int helper(vector<int>& nums, bool* isVisited, int i) {
    if (isVisited[i]) return 0;

    isVisited[i] = true;

    return 1 + helper(nums, isVisited, nums[i]);
  }
};