#include <limits.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 就跟之前包禮物演算法一樣
 * 直接從上到下掃描之類的？
 */

/**
 * 偷看到了 priority_queue 的標籤
 * 不過這題蠻有趣的
 * 應該可以跟刮水題、在 2D 排序陣列搜尋題並列吧
 */

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // 高度, 結束位置
    priority_queue<pair<int, unsigned int>> pq;
    pq.push({0, (unsigned int)INT_MAX + 1});

    vector<vector<int>> result;
    int size = buildings.size();

    int x = -1;  // 現在畫出 skyline 的 x 位置

    for (vector<int>& building : buildings) {
      // 現在最高的位置已經過氣了
      // 可以製造下降階梯
      while (pq.top().second < building[0]) {
        x = pq.top().second;

        // pop 直到樓梯的結尾在現在的後面
        // 要是樓梯的結尾前面
        // 那無法形成下降階梯
        do {
          pq.pop();
        } while (pq.top().second <= x);

        result.push_back({x, pq.top().first});
      }

      // 新加入的建築物比之前還高
      if (building[2] > pq.top().first) {
        if (x == building[0]) {
          // 如果 x 開始的位置一樣
          // 那就改變高度就好
          result.back()[1] = building[2];
        } else {
          // 遇到上升階梯
          x = building[0];
          result.push_back({building[0], building[2]});
        }
      }

      pq.push({building[2], building[1]});
    }

    size = pq.size() - 1;

    // 與上面的迴圈一樣
    // 製造下降階梯
    while (pq.size() != 1) {
      x = pq.top().second;

      do {
        pq.pop();
      } while (pq.top().second <= x);

      result.push_back({x, pq.top().first});
    }

    return result;
  }
};