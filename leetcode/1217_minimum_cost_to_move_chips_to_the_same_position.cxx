#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int minCostToMoveChips(vector<int>& position) {
    int oddSum = 0;
    int evenSum = 0;
    int size = position.size();

    for (int& p : position) {
      if (p % 2 == 0) {
        evenSum++;
      } else {
        oddSum++;
      }
    }

    if (evenSum > oddSum) return oddSum;

    return evenSum;
  }
};