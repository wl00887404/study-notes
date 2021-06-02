#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 最佳解是檢查重複耶 WTF
 * TODO: 試試看 seen
 */

class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> results;

    permuteUnique(results, nums, length);

    return results;
  }
  void permuteUnique(vector<vector<int>>& results, vector<int>& nums, int k) {
    if (k == 1) return results.push_back(nums);

    unordered_set<int> used;

    permuteUnique(results, nums, k - 1);
    used.insert(nums[k - 1]);

    for (int i = 0; i < k - 1; i++) {
      if (used.count(nums[i])) continue;

      swap(nums[i], nums[k - 1]);
      used.insert(nums[k - 1]);
      permuteUnique(results, nums, k - 1);
      /**
       * 因為偶數項執行時 nums[0] 會與 nums[1] 交換
       * 所以回到奇數項時
       * 只需要將 nums[0] （原本的 nums[1] ） 與 nums[k-1] 交換即可
       *
       * 但在 used 的情況下，有可能不會交換而卡住，
       * swap back 確保一直原本的組合才不會卡住
       */
      swap(nums[i], nums[k - 1]);
    }
  }
} solution;

int main() {
  vector<int> nums = {2, 2, 3, 3};
  vector<vector<int>> results = solution.permuteUnique(nums);

  return 0;
}