#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 從後面回來比較好，因為往下掉的元素就不會再改了
 */

class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int m = box.size();
    int n = box[0].size();

    vector<vector<char>> result(n, vector<char>(m, '.'));

    for (int i = 0; i < m; i++) {
      int lastIndex = n - 1;

      for (int j = n - 1; j >= 0; j--) {
        if (box[i][j] == '#') {
          result[lastIndex][m - 1 - i] = '#';
          lastIndex--;
          continue;
        }
        if (box[i][j] == '*') {
          result[j][m - 1 - i] = '*';
          lastIndex = j - 1;
        }
      }
    }

    return result;
  }
};