#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 原陣列
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * 橫向連續加總的
 * 1 0 1 0 0
 * 1 0 1 2 3
 * 1 2 3 4 5
 * 1 0 0 1 0
 *
 * 第一行就是橫向連續加總
 * 第二行為現在上一行能形成的矩形
 * 但是要限制最大寬度
 * 或是由左累積取一個大的
 *
 * 0 1 2 3
 * 0 1 2 3
 * 1 2 3 4
 *
 * 上面最多 3 * 2
 * 下面雖然有 4 但是也只能形成 3 * 3
 *
 * 欸不對
 * 應該是來自左側可能形成的矩形
 * 與來自上側可能形成的矩形
 */

/**
 * 1 1 1 0 0
 * 1 1 1 1 1
 * 1 1 1 1 1
 * 0 1 1 1 1
 *
 * 1 2 3 0 0
 * 1 2 3 4 5
 * 1 2 3 4 5
 * 1 2 3 4 5
 * 0 1 2 3 4
 *
 * 1 1 1 0 0
 * 2 2 2 1 1
 * 3 3 3 2 2
 * 4 4 4 3 3
 * 0 5 5 4 4
 *
 * 假設是兩個矩行重疊
 * 要怎麼
 *
 * 假設我同時使用直累積與橫累積
 * 我至少可以立即確定某點能形成 L
 * 左上也要能完成同樣的 L
 * 左上可以是會是計算過的點
 */

/**
 * L 重疊的方法好像不太可靠
 * 相關題是關鍵題 84 題是關鍵
 */

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
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
      result = max(result, largestRectangleArea(histograms[i]));
    }

    return result;
  }

 private:
  int m;
  int n;
  // 直接從 84 題複製
  int largestRectangleArea(int* heights) {
    stack<int> stack;
    int result = 0;

    for (int i = 0; i < n; i++) {
      int& height = heights[i];
      while (!stack.empty() && height < heights[stack.top()]) {
        int j = stack.top();
        stack.pop();

        if (stack.empty()) {
          result = max(result, heights[j] * i);
        } else {
          result = max(result, heights[j] * (i - stack.top() - 1));
        }
      }

      stack.push(i);
    }

    while (!stack.empty()) {
      int i = stack.top();
      stack.pop();

      if (stack.empty()) {
        result = max(result, heights[i] * n);
      } else {
        result = max(result, heights[i] * (n - stack.top() - 1));
      }
    }

    return result;
  }
} solution;

int main() {
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};

  solution.maximalRectangle(matrix);
  return 0;
}