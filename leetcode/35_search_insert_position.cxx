#include <iostream>
#include <vector>
using namespace std;

/**
 * **You may assume no duplicates in the array.**
 * 
 * TODO: 寫一個 binary search 的版本
 */

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int length = nums.size();

    if (length == 0) return 0;

    for (int i = 0; i < length; i++) {
      if (target <= nums[i]) return i;
    }

    return length;
  }
} solution;

int main() {
  vector<int> nums = {1, 3, 5};
  int target = 2;

  cout << solution.searchInsert(nums, target) << endl;

  return 0;
}