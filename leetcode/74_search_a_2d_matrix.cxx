#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 關聯題 240
 *
 * binary search 垂直一次
 * binary search 橫的一次
 * 應該就可以了吧
 */

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    if (matrix[0][0] > target || matrix[m - 1][n - 1] < target) return false;

    int left = 0;
    int right = m;

    while (left < right) {
      int mid = (left + right) / 2;

      if (matrix[mid][0] == target) return true;
      if (matrix[mid][0] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    // left 會停在下一行
    // 所以要 - 1
    int i = left - 1;

    left = 0;
    right = n;

    while (left < right) {
      int mid = (left + right) / 2;

      if (matrix[i][mid] == target) return true;
      if (matrix[i][mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return false;
  }
};