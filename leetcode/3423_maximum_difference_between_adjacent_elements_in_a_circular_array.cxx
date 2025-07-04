#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxAdjacentDistance(vector<int>& nums) {
    int result = INT_MIN;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      int next = (i + 1) % size;

      result = max(result, abs(nums[next] - nums[i]));
    }

    return result;
  }
};