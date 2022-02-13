#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 題意：
 *   袋子裡有一堆豆豆，只能移除豆子
 *   可以把袋子清空，或是都調整成一樣的數字
 */

class Solution {
 public:
  long long minimumRemoval(vector<int>& beans) {
    sort(beans.begin(), beans.end());
    
    // 假設選擇某個元素
    // 在這 index 之前全部加起來
    // 在這 index 後面全部扣掉該值

    long long sumBefore = 0;
    long long sumAfter = 0;

    for (int& bean : beans) {
      sumAfter += bean;
    }

    long long result = sumAfter + 1;
    int size = beans.size();
    for (int i = 0; i < size; i++) {
      int& bean = beans[i];

      sumAfter -= bean;  // 調整 sumAfter 為正確值

      long long nextResult = sumBefore;  // 前面的全部移除

      // 後面的全部扣掉該值
      long long shouldRemove = bean;
      shouldRemove *= size - i - 1;
      nextResult += sumAfter - shouldRemove;

      result = min(result, nextResult);

      sumBefore += bean;  // 調整 sumAfter 為正確值
    }

    return result;
  }
};