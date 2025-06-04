
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 從 3372 挫敗來這裡
 *
 * 這裡是有向圖，節點 i 可以連結到 edges[i]
 * 給定 node1 與 node2，找出一節點 node a
 * 使 node1 與 node2 都可到達，且距離最小
 * 如果 node a 不存在，回傳 -1
 */

 /**
  * 兩個節點同時往前走一步
  * 如果走到對方走過的節點，那就是 node a
  * 如果走到自己重複的節點，那就是發現環了，不用再繼續走
  */

class Solution {
 public:
  int closestMeetingNode(vector<int>& edges, int begin1, int begin2) {
    // 如果同時有兩個解，要回傳 index 比較小的那個
    return min(helper(edges, begin1, begin2), helper(edges, begin2, begin1));
  }

  int helper(vector<int>& edges, int node1, int node2) {
    int size = edges.size();
    vector<bool> visted1(size, false);
    vector<bool> visted2(size, false);

    while (node1 != -1 || node2 != -1) {
      if (node1 != -1) {
        // 這個節點已經被 node2 拜訪過了，狂喜
        if (visted2[node1]) return node1;

        if (visted1[node1]) {
          // 拜訪到了以前拜訪的節點，node1 不用再繼續了
          node1 = -1;
        } else {
          // 拜訪訪了新節點
          visted1[node1] = true;
          node1 = edges[node1];  // node1 移動到下一個節點
        }
      }

      if (node2 != -1) {
        // 這個節點已經被 node1 拜訪過了，狂喜
        if (visted1[node2]) return node2;

        if (visted2[node2]) {
          // 拜訪到了以前拜訪的節點，node1 不用再繼續了
          node2 = -1;
        } else {
          // 拜訪訪了新節點
          visted2[node2] = true;
          node2 = edges[node2];  // node2 移動到下一個節點
        }
      }
    }

    return -1;
  }
};