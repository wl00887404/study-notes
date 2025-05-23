#include <iostream>
#include <vector>
using namespace std;

/**
 * TODO: 研究空間複雜度 1 的解
 * https://www.youtube.com/watch?v=BnCJaHiSodg
 */

class Solution2021 {
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

/**
 * 2025 再次寫這一題
 * 目標是要 Space  O(1)
 *
 * O(m + n) 的做法，應該就是記下 i 有 0，或是 j 有 0
 * 之後遍歷到再針對 matrix[m][j] 與 matrix[i][n] 去修改 0
 *
 * 最麻煩的就是改到之後的元素，會把更動後的 0 誤以爲是要觸發的元素
 * 把之後要變成 0 的元素，變成沒用到的一個特別的數字呢？
 * 或是我有一個遍歷模式，不會遇到被修改過的 0
 *
 *
 * 想不到上述的做法
 * 不如 m n 最大是 200，開一個 bitset 吧
 * 不過這樣也是沒有 O(n) 吧
 */
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    bitset<200> mFlags;
    bitset<200> nFlags;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] != 0) continue;

        mFlags.set(i);
        nFlags.set(j);
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!mFlags.test(i) && !nFlags.test(j)) continue;

        matrix[i][j] = 0;
      }
    }
  }
};