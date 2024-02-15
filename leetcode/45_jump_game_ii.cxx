#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int last = nums.size() - 1;

    if (last == 0) return 0;
    if (nums[0] >= last) return 1;

    int i = 1;
    int result = 0;
    int limit = nums[0];
    int nextLimit = 0;

    while (true) {
      int tempLimit = nums[i] + i;

      if (tempLimit >= last) break;

      if (tempLimit > nextLimit) nextLimit = tempLimit;

      if (i == limit) {
        limit = nextLimit;
        nextLimit = 0;
        result++;
      }

      i++;
    }

    result += 2;

    return result;
  }
} solution;

int main() {
  vector<int> nums = {2, 1, 1, 2, 1, 4};
  //                  ^     ^  ^

  cout << solution.jump(nums) << endl;

  return 0;
}
