#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int length = nums.size();
    int zeroLength = 0;

    for (int i = 0; i < length; i++) {
      if (nums[i] == 0) {
        zeroLength++;
      } else if (zeroLength != 0) {
        nums[i - zeroLength] = nums[i];
      }
    }

    for (int i = 0; i < zeroLength; i++) {
      nums[length - i - 1] = 0;
    }
  }
} solution;

int main() {
  vector<int> nums = {0, 1, 0, 3, 12};
  // vector<int> nums = {1, 2};

  solution.moveZeroes(nums);

  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << endl;
  }

  return 0;
}