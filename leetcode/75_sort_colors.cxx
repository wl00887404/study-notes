#include <vector>

using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int red = 0;
    int white = 0;
    int blue = 0;

    for (int& num : nums) {
      if (num == 0) red++;
      if (num == 1) white++;
      if (num == 2) blue++;
    }

    int i = 0;

    while (red--) {
      nums[i] = 0;
      i++;
    }

    while (white--) {
      nums[i] = 1;
      i++;
    }
    while (blue--) {
      nums[i] = 2;
      i++;
    }
  }
};