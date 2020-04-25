#include <iostream>
#include <vector>
using namespace std;

/**
 * brute force: 744 ms
*/

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int length = nums.size();
    int result = 0;

    for (int i = 0; i < length; i++) {
      int sum = 0;

      for (int j = i; j < length; j++) {
        sum += nums[j];

        if (sum == k) result++;
      }
    }

    return result;
  }
};