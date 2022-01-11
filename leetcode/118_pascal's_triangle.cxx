
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;

    result.push_back({1});
    if (numRows == 1) return result;

    for (int i = 2; i <= numRows; i++) {
      result.push_back({});
      result[i - 1].resize(i);
      result[i - 1][0] = 1;
      result[i - 1][i - 1] = 1;

      for (int j = 1; j < (i + 1) / 2; j++) {
        result[i - 1][j] = result[i - 2][j - 1] + result[i - 2][j];
        result[i - 1][i - j - 1] = result[i - 1][j];
      }
    }

    return result;
  }
};