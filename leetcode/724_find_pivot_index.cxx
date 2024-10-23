#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int size = nums.size();
    int pivot = 0;
    int leftSum = 0;
    int rightSum = 0;

    for (int& num : nums) {
      rightSum += num;
    }

    while (pivot < size) {
      if (pivot - 1 > 0) {
        leftSum += nums[pivot - 1];
      }

      rightSum -= nums[pivot];

      if (leftSum == rightSum) return pivot;

      pivot++;
    }

    return -1;
  }
};