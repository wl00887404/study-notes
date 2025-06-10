#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int largestCombination(vector<int>& candidates) {
    int result = 0;

    int maximum = 0;
    for (const int& c : candidates) {
      maximum = max(maximum, c);
    }

    for (int i = 0; i < 31; i++) {
      int bit = 1 << i;
      // 已經比最大的數還大了，不可能可以 and 後來 > 0
      if (bit > maximum) break;

      // 單獨看某個 bit，可以 and 幾個 candidates
      int count = 0;
      for (const int& c : candidates) {
        if ((c & bit) != 0) {
          count++;
        }
      }

      result = max(result, count);
    }

    return result;
  }
};