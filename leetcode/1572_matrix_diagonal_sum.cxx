#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int result = 0;
    int size = mat.size();

    for (int i = 0; i < size; i++) {
      result += mat[i][i];
      result += mat[size - i - 1][i];
    }

    if (size % 2 == 1) result -= mat[size / 2][size / 2];

    return result;
  }
};