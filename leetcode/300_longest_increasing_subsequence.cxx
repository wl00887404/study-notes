#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 用我的邏輯寫吧
 * 序列產生很簡單，就要跟不要
 * 要的話，長度 + 1 ，最小值為它
 * 不要的話，長度不變，不改變最小值
 *
 * 不理想的情況
 * 是前面選了大的導致後面選不了
 *
 * 優化方向呢？
 * http://web.ntnu.edu.tw/~algo/Subsequence.html
 * 依據 min 大小記憶？
 * 不可行，影響的不是只有 min
 * [0, 10, 20, 1, 2, 3, 11, 12, 12, 21, 22, 23]
 */

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    unordered_map<int, int> cache[nums.size()];

    return lengthOfLIS(nums, 0, NULL, cache);
  }
  int lengthOfLIS(vector<int>& nums, int i, int* min,
                  unordered_map<int, int>* cache) {
    if (i >= nums.size()) return 0;
    if (min && cache[i].count(*min)) return cache[i][*min];

    int notSelectedResult = lengthOfLIS(nums, i + 1, min, cache);
    if (min != NULL && *min >= nums[i]) return notSelectedResult;

    int selectedResult = 1 + lengthOfLIS(nums, i + 1, &nums[i], cache);
    int result = max(notSelectedResult, selectedResult);

    if (min) cache[i][*min] = result;

    return result;
  }
} solution;

int main() {
  vector<int> nums = {0, 10, 20, 1, 2, 3, 11, 12, 12, 21, 22, 23};
  solution.lengthOfLIS(nums);

  return 0;
}
