#include <iostream>
#include <vector>

using namespace std;

/**
 * subset 就是那種「要」、「不要」的老題目了
 */

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> temp;

    size = nums.size();
    numsPointer = &nums;

    helper(result, temp, 0);

    return result;
  }

  int size;
  vector<int>* numsPointer;

  void helper(vector<vector<int>>& result, vector<int>& temp, int i) {
    if (i == size) {
      return result.push_back(temp);
    }

    // 不納入 i
    helper(result, temp, i + 1);

    vector<int>& nums = *numsPointer;
    // 納入 i
    temp.push_back(nums[i]);
    helper(result, temp, i + 1);
    temp.pop_back();
  }
};