#include <iostream>
#include <vector>

using namespace std;

/**
 * 與 442 相同
 * 可以在原本的 array 上動手腳
 */

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int size = nums.size();

    for (int& num : nums) {
      int value = abs(num) - 1;

      if (nums[value] > 0) nums[value] *= -1;
    }

    vector<int> result;

    for (int i = 0; i < size; i++) {
      if (nums[i] > 0) {
        result.push_back(i + 1);
      }
    }

    return result;
  }
};