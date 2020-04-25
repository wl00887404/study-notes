#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int last = nums.size() - 1;
    int result = 0;

    while (last != 0) {
      int i = 0;
      while (nums[i] < last - i) i++;
      last = i;
      result++;
    }

    return result;
  }
} solution;

int main() {
  vector<int> nums = {2, 3, 1, 1, 4};

  cout << solution.jump(nums) << endl;

  return 0;
}
