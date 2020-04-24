#include <iostream>
#include <vector>
using namespace std;

/**
 * T1 是發現 0 後檢查能不能走到這步
 * 是我原本的想法耶 可惜
 * TODO: 敢不敢再快一點
 */

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int steps = nums[0];
    int length = nums.size();

    for (int i = 1; i < length; i++) {
      if (steps < 1) return false;

      steps--;
      if (nums[i] > steps) steps = nums[i];
    }

    return true;
  }
} solution;

int main() {
  // vector<int> nums = {2, 3, 1, 1, 4};
  vector<int> nums = {3, 2, 1, 0, 4};

  cout << solution.canJump(nums) << endl;

  return 0;
}