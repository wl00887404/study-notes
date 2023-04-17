#include <iostream>
#include <vector>

using namespace std;

/**
 * 我記得是長這樣
 * c(0, 0)
 * c(1, 0) c(1, 1)
 * c(2, 0) c(2, 1) c(2, 2)
 * c(3, 0) c(3, 1) c(3, 2) c(3, 3)
 */

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result(rowIndex + 1);
    result[0] = 1;

    for (int i = 0; i <= rowIndex; i++) {
      result[i] = c(rowIndex, i);
    }

    return result;
  }

  int c(int n, int k) {
    long long result = 1;
    int j = 2;
    for (int i = 0; i < k; i++) {
      result *= n - i;

      while (j <= k && result % j == 0) {
        result /= j;
        j++;
      }
    }

    return result;
  }
};