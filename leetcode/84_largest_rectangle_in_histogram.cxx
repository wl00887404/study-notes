#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 85 的前置題
 *       x
 *     x x
 *     x x
 *     x x   x
 * x   x x x x
 * x x x x x x
 *
 * 矩型面積是最小高度 * 寬度
 * 最小高度可以區分很多區段
 */

/**
 * 怎麼想都是 O(n^2) 呀
 *
 * 偷看一下解答
 * https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/452612/Thinking-Process-for-Stack-Solution
 *
 * [1, 3, 2, 1, 5, 6, 2, 3]
 *
 * 1 進了 stack
 *
 * 3 進入 stack
 *
 * 2 比 3 小
 * 表示 3 已經無法形成更大的矩形
 * 計算 3 * 1
 * 2 進入 stack
 *
 * 1 比 2 小
 * 表示 2 已經無法形成更大的矩形
 * 計算 2 * 2
 * 2 進入 stack
 *
 * 當高度下降就可以計算前一個矩型
 * 前一個矩型的寬度會是比這個高度更低的位置
 */

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    //  poisition
    stack<int> stack;
    int size = heights.size();
    int result = 0;

    for (int i = 0; i < size; i++) {
      int& height = heights[i];
      // 如果 stack.top 是 6
      // 此時遇到 2
      // 表示無法再使用 6 形成矩形
      while (!stack.empty() && height < heights[stack.top()]) {
        int j = stack.top();
        stack.pop();

        if (stack.empty()) {
          // 沒有比現在最小的了
          // 此點有可能為波谷
          // 前方有比它高的山
          // 所以直接乘上現在的 i
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
        result = max(result, heights[i] * size);
      } else {
        result = max(result, heights[i] * (size - stack.top() - 1));
      }
    }

    return result;
  }
};