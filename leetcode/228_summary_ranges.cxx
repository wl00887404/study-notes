#include <istream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    int size = nums.size();
    vector<string> results;

    int i = 0;
    while (i < size) {
      int j = i + 1;
      while (j < size && nums[j - 1] + 1 == nums[j]) j++;

      if (j - i == 1) {
        results.push_back(to_string(nums[i]));
      } else {
        results.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
      }

      i = j;
    }

    return results;
  }
};