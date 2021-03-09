#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int size = nums.size();
    int result = 0;
    for (int i = 0; i < size; i++) result += (i - nums[i]);

    return result + size;
  }
} solution;

int main() {
  vector<int> nums = {3, 0, 1};
  cout << solution.missingNumber(nums) << endl;

  return 0;
}