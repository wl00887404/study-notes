#include <iostream>
#include <vector>
using namespace std;

/**
 * Tortoise and Hare Algorithm
 * http://web.ntnu.edu.tw/~algo/Function.html
 */

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int turtle = nums[0];
    int rabbit = nums[0];

    do {
      turtle = nums[turtle];
      rabbit = nums[nums[rabbit]];
    } while (turtle != rabbit);

    turtle = nums[0];

    while (turtle != rabbit) {
      turtle = nums[turtle];
      rabbit = nums[rabbit];
    }

    return turtle;
  }
} solution;

int main() {
  // vector<int> nums = {1, 3, 4, 2, 2};
  // vector<int> nums = {3, 1, 3, 4, 2};
  vector<int> nums = {1, 2, 1, 4, 3};

  cout << solution.findDuplicate(nums) << endl;

  return 0;
}