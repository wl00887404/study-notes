#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 研究空間複雜度 1 的解
 * https://www.youtube.com/watch?v=BnCJaHiSodg
 */

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int yLength = matrix.size();
    int xLength = matrix[0].size();
    // z means zeroize
    bool zys[yLength];
    for (int i = 0; i < yLength; i++) zys[i] = false;
    bool zxs[xLength];
    for (int i = 0; i < xLength; i++) zxs[i] = false;

    for (int y = 0; y < yLength; y++) {
      for (int x = 0; x < xLength; x++) {
        if (matrix[y][x] != 0) continue;
        zys[y] = 1;
        zxs[x] = 1;
      }
    }

    for (int y = 0; y < yLength; y++) {
      vector<int>& rows = matrix[y];
      for (int x = 0; x < xLength; x++) {
        if (zys[y] || zxs[x]) matrix[y][x] = 0;
      }
    }
  }
};