#include <vector>
using namespace std;

class Solution {
 public:
  int countSubarrays(vector<int>& nums) {
    int size = nums.size();
    int result = 0;

    for (int i = 0; i + 2 < size; i++) {
      if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
        result++;
      }
    }

    return result;
  }
};