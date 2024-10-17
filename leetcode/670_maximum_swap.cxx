
#include <iostream>
#include <vector>

using namespace std;

/**
 * 越前面的數字，要找後面比自己大越多的交換
 */

class Solution {
 public:
  int maximumSwap(int num) {
    vector<short> nums;
    vector<short> maximums;
    vector<short> maximumIndexes;
    short maximum = -1;
    short maximumIndex = -1;
    short i = 0;

    while (num != 0) {
      if (num % 10 > maximum) {
        maximum = num % 10;
        maximumIndex = i;
      }

      nums.push_back(num % 10);
      maximums.push_back(maximum);
      maximumIndexes.push_back(maximumIndex);
      num /= 10;
      i++;
    }

    short size = nums.size();

    for (short i = size - 1; i > 0; i--) {
      if (maximums[i] <= nums[i]) continue;

      short& toSwapIndex = maximumIndexes[i];

      nums[toSwapIndex] = nums[i];
      nums[i] = maximums[i];

      break;
    }

    int result = 0;
    for (short i = size - 1; i >= 0; i--) {
      result *= 10;
      result += nums[i];
    }

    return result;
  }
};