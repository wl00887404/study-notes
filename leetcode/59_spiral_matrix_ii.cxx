#include <iostream>
#include <vector>

using namespace std;

/**
 * [[1]]
 * [
 *   [1, 2, 3],
 *   [8, 9 ,4],
 *   [7, 6 ,5],
 * ]
 *
 * [
 *   [1, 2, 3, 4],
 *   [12, 13, 14, 5],
 *   [11, 16, 15, 6],
 *   [10, 9, 8, 7],
 * ]
 */

// 哇靠， Github Copilot 註解寫一寫，就可以產 code 了
class CopilotSolution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int top = 0, left = 0, right = n, bottom = n;
    int count = 1;

    while (left < right && top < bottom) {
      for (int i = left; i < right; i++) {
        matrix[top][i] = count++;
      }
      for (int i = top + 1; i < bottom; i++) {
        matrix[i][right - 1] = count++;
      }
      for (int i = right - 2; left <= i; i--) {
        matrix[bottom - 1][i] = count++;
      }
      for (int i = bottom - 2; top < i; i--) {
        matrix[i][left] = count++;
      }

      top++;
      left++;
      right--;
      bottom--;
    }

    return matrix;
  }
};

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    this->n = n;
    resultPointer = &result;

    helper(0, 1);

    return result;
  }

  int n;
  vector<vector<int>>* resultPointer;

  // i 是第幾層
  void helper(int i, int counter) {
    if (i * 2 > n) return;

    vector<vector<int>>& result = *resultPointer;
    int j = i;
    int k = i;

    // 往右
    while (k < n - i) {
      result[j][k] = counter++;
      k++;
    }
    k--;

    j++;  // 往下
    while (j < n - i) {
      result[j][k] = counter++;
      j++;
    }
    j--;

    k--;  // 往左
    while (k >= i) {
      result[j][k] = counter++;
      k--;
    }
    k++;

    j--;  // 往上
    while (j > i) {
      result[j][k] = counter++;
      j--;
    }

    helper(i + 1, counter);
  }
} solution;

int main() {
  int n = 3;
  vector<vector<int>> result = solution.generateMatrix(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}