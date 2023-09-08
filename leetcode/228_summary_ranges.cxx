#include <istream>
#include <vector>

using namespace std;

/**
 * 回傳結果要包含 nums 所有數字
 * 也就是把連號刪掉
 * 濃縮成範圍
 */

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    int size = nums.size();
    int i = 0;
    vector<string> result;

    while (i < size) {
      string s = to_string(nums[i]);
      int j = i;
      // 省略連號
      while (j + 1 < size && nums[j] + 1 == nums[j + 1]) {
        j++;
      }

      if (i != j) {
        s += "->" + to_string(nums[j]);
      }

      i = j + 1;

      result.push_back(s);
    }

    return result;
  }
};