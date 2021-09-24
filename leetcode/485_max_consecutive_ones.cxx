#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 0;
    int length = 0;

    for (int& num : nums) {
      if (num == 0) {
        length = 0;
      } else {
        length++;
        result = max(result, length);
      }
    }

    return result;
  }
};
