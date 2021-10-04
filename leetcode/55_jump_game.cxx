#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int steps = nums[0];
    int length = nums.size();

    for (int i = 1; i < length; i++) {
      // 如果沒有步數了就失敗
      if (steps < 1) return false;

      // 往前探索一步
      steps--;

      // 如果這格可以補充的部署比現在還多
      // 那就補充步數
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