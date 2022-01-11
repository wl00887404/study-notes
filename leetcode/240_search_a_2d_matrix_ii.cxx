#include <iostream>
#include <vector>

using namespace std;

/**
 * matrix[m][n] > matrix[m - 1][n]
 * matrix[m][n] > matrix[m][n - 1]
 * 但是 matrix[m - 1][n] 與 martix[m][n-1] 不知道誰大
 *
 * 區域最小一定是左上角
 * 區域最大一定是右下角
 */

/**
 * 先橫的 binary search 一次會有搞頭嗎？
 * Example 1 :
 *  1  4  7 11 15
 *  2  5  8 12 19
 *  3  6  9 16 22
 * 10 13 14 17 24
 * 18 21 23 26 30
 *
 * 假設我要找 16
 * 第一列會判斷 16 應該要在 15 那列
 * 第一行會判斷 16 應該要在 10 那行
 * 所以沒搞頭
 */

/**
 * 假設在第一列找到 a < target < b
 * 第二列有 c 、 d ，其中 a < c 且 b < d
 * 則 a < target < b < d
 * c 有可能為 target
 * 所以 target 一定在 a 這一行
 *
 * 3 4 10
 * 5 6 11
 *
 * 假設我要找 5
 * 第一列可以在 4 10 中找到
 * 但 5 可能在左側
 * 這個方法也失敗
 */

/**
 * 沒轍了
 * 只能 binary search 一行一行找
 * 這個的執行時間與直接 find 差不多
 */
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    matrixPointer = &matrix;
    this->target = target;

    int m = matrix.size();
    int n = matrix[0].size();

    if (m > n) {
      for (int j = 0; j < n; j++) {
        if (binarySearchN(j, 0, m)) return true;
      }
    } else {
      for (int i = 0; i < m; i++) {
        if (binarySearchM(i, 0, n)) return true;
      }
    }

    return false;
  }

  int target;
  vector<vector<int>>* matrixPointer;

  bool binarySearchM(int i, int begin, int end) {
    vector<vector<int>>& matrix = *matrixPointer;

    while (begin < end) {
      int mid = (begin + end) / 2;

      if (matrix[i][mid] == target) return true;

      if (matrix[i][mid] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }

    return false;
  }

  bool binarySearchN(int j, int begin, int end) {
    vector<vector<int>>& matrix = *matrixPointer;

    while (begin < end) {
      int mid = (begin + end) / 2;

      if (matrix[mid][j] == target) return true;

      if (matrix[mid][j] < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }

    return false;
  }
};

// O(m * n) 直接找也可以過
class findSolution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (vector<int>& row : matrix) {
      for (int& val : row) {
        if (val == target) return true;
      }
    }
    return false;
  }
};

/**
 * https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66139/C%2B%2B-search-from-top-right
 * 討論區的想法太神了吧
 * 跟最右上角的比
 * 如果比右上角大，那這一列都會比目標小，就可以直接刪掉一行
 * 如果比右上角小，那這一行都會比目標大，就可以直接刪掉一列
 *
 * 這一個陣列就會像是一棵二元搜尋數
 *
 *  1  4  7 11 15
 *  2  5  8 12 19
 *  3  6  9 16 22
 * 10 13 14 17 24
 * 18 21 23 26 30
 *
 * 15 => 19 => 22
 *          => 12
 *    => 11 => 12
 *          =>  7
 *
 * TODO: 明天實作它
 */