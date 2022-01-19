
#include <iostream>
#include <vector>

using namespace std;

/**
 * 這題跟 300 差不多吧
 * 只是要找最長的
 *
 * nums =  [2, 1, 5, 0, 4, 6]
 *
 * 要找到遞增的
 *
 * 0: 2
 *
 * 1: 2
 *    1
 *
 * 2: 2 5
 *    1 5
 *
 * 3: 2 5
 *    1 5
 *    0
 *
 * 4: 2 5
 *    1 5
 *    0 4
 *
 * 5: 2 5 6
 *    1 5 6
 *    0 4 6
 *
 */

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    if (nums.size() < 3) return false;

    vector<int> result(3);
    int length = 0;

    for (int& num : nums) {
      int i = 0;
      for (; i < length; i++) {
        if (num > result[i]) continue;
        result[i] = num;
        break;
      }

      if (i == length) {
        result[length] = num;
        length++;
      }

      if (length == 3) return true;
    }

    return false;
  }
};