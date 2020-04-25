#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int length = nums.size();

    if (length < 2) return length;

    int j = 1;

    for (int i = 1; i < length; i++) {
      if (nums[i] == nums[i - 1]) continue;
      
      nums[j] = nums[i];
      j++;
    }

    return j;
  }
};