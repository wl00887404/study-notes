#include <iostream>
#include <vector>
using namespace std;

/**
 *  0          => 0 (00000)
 *  1 =  1 + 0 => 1 (00001)
 *  2 =  2 + 0 => 1 (00010)
 *  3 =  2 + 1 => 2 (00011)
 *  4 =  4 + 0 => 1 (00100)
 *  5 =  4 + 1 => 2 (00101)
 *  6 =  4 + 2 => 2 (00110)
 *  7 =  4 + 3 => 3 (00111)
 *  8 =  8 + 0 => 1 (01000)
 *  9 =  8 + 1 => 2 (01001)
 * 10 =  8 + 2 => 2 (01010)
 * 11 =  8 + 3 => 3 (01011)
 * 12 =  8 + 4 => 2 (01100)
 * 13 =  8 + 5 => 3 (01101)
 * 14 =  8 + 6 => 3 (01110)
 * 15 =  8 + 7 => 4 (01111)
 * 16 = 16 + 0 => 1 (10000)
 * 17 = 16 + 1 => 2 (10001)
 */

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> result = {0};
    int i = 1;
    int nextLength = 1;
    int length = 1;
    while (i <= num) {
      result.push_back(1 + result[i - length]);

      i++;
      length--;
      if (length == 0) {
        nextLength *= 2;
        length = nextLength;
      }
    }

    return result;
  }
} solution;

int main() {
  vector<int> result = solution.countBits(17);

  for (int i : result) cout << i << endl;

  return 0;
}