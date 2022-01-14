#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 *
 * 好啦是該回來想想這題的
 * 85 是從 84 來的
 * 從長條圖找到最大的矩形
 *
 * 這題一樣的概念可以從長條圖找最大的正方型嗎？
 *
 * 欸不對
 * 我可以直接用 84 的算法
 * 但是公式用正方形的就好
 */

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();

    int histograms[m][n];

    for (int j = 0; j < n; j++) {
      histograms[0][j] = matrix[0][j] - '0';
    }

    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '0') {
          histograms[i][j] = 0;
        } else {
          histograms[i][j] = histograms[i - 1][j] + 1;
        }
      }
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
      result = max(result, largestSquareArea(histograms[i]));
    }

    return result;
  }

  int m;
  int n;

  int largestSquareArea(int* heights) {
    stack<int> stack;
    int result = 0;

    for (int i = 0; i < n; i++) {
      int& height = heights[i];
      while (!stack.empty() && height < heights[stack.top()]) {
        int j = stack.top();
        stack.pop();
        int width = stack.empty() ? i : i - stack.top() - 1;

        result = max(result, square(min(width, heights[j])));
      }

      stack.push(i);
    }

    while (!stack.empty()) {
      int j = stack.top();
      stack.pop();
      int width = stack.empty() ? n : n - stack.top() - 1;

      result = max(result, square(min(width, heights[j])));
    }

    return result;
  }

  int square(int x) { return x * x; }
};

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int result = 0;

    int dp[m][n];

    for (int i = 0; i < m; i++) {
      dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
      result = max(result, dp[i][0]);
    }

    for (int j = 0; j < n; j++) {
      dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
      result = max(result, dp[0][j]);
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == '0') {
          dp[i][j] = 0;
          continue;
        }

        // 自己的左上、上、左都要能夠形成一樣大的正方形
        dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        result = max(result, dp[i][j]);
      }
    }

    return result * result;
  }

  int min3(int& x, int& y, int& z) { return min(min(x, y), z); }
};
