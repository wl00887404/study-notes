#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 找到每日溫度要等多久才能遇到更高的溫度
 * Input:  [73, 74, 75, 71, 69, 72, 76, 73]
 * Output: [ 1,  1,  4,  2,  1,  1,  0,  0]
 *
 * 想法應該跟 84 一樣
 * 如果持續下降全部塞進 stack 中
 * 遇到比 stack.top 高的就開始 pop
 */

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    // 最冷溫度的 index
    stack<int> stack;
    int size = temperatures.size();
    vector<int> result(size, 0);
    stack.push(0);

    for (int i = 1; i < size; i++) {
      // 上一個最低溫比現在還低溫時
      while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
        result[stack.top()] = i - stack.top();
        stack.pop();
      }

      stack.push(i);
    }

    return result;
  }
};