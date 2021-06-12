#include <iostream>
#include <vector>
using namespace std;

/**
 * 跟上次一樣
 * 只是這次去頭或去尾
 */

class Solution {
 public:
  int rob(vector<int>& nums) {
    int length = nums.size();
    if (length == 1) return nums[0];

    int cache[length];
    for (int i = 0; i < length; i++) cache[i] = -1;

    int withoutHeadResult = rob(nums, cache, 1, length);

    length--;
    for (int i = 0; i < length; i++) cache[i] = -1;

    int withHeadResult = rob(nums, cache, 0, length);

    return max(withHeadResult, withoutHeadResult);
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