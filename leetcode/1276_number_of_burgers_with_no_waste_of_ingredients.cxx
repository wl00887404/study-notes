#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    // j is Jumbo Burger
    // s is Small Burger
    // 4j + 2s = tomatoSlices
    // j + s = cheeseSlices
    // 解出 [j, s]

    int j = tomatoSlices - cheeseSlices * 2;
    if (j < 0 || j % 2 != 0) return {};

    j /= 2;
    int s = cheeseSlices - j;
    if (s < 0) return {};

    return {j, s};
  }
};