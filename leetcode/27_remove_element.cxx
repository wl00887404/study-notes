#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int j = 0;
    int length = nums.size();

    for (int i = 0; i < length; i++) {
      if (nums[i] == val) {
        j++;
      } else if (j != 0) {
        nums[i - j] = nums[i];
      }
    }

    return length - j;
  }
};