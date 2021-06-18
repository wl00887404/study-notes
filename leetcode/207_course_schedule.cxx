#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 有向圖偵測有沒有環
 * 分支要怎麼處理
 *
 * 發現移除根葉就是最佳解
 *
 * Kahn's algorithm
 *
 * 很詳細的 medium
 * https://medium.com/@ryanyang1221/leetcode-challenge-5-29-course-schedule-%E4%B8%89%E9%83%A8%E6%9B%B2%E5%A4%A7%E7%A6%AE%E5%8C%85-%E4%B8%8A-64d17fa5b1ba
 * 基本上就是拓撲排序
 * https://zh.wikipedia.org/wiki/%E6%8B%93%E6%92%B2%E6%8E%92%E5%BA%8F
 *
 */
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    /**
     * type prerequisite = [此課程, 先修課程]
     * type prerequisites = prerequisite[]
     */

    int length = prerequisites.size();
    if (!length) return true;

    int inDegrees[numCourses];
    bool isRemoved[length];
    for (int i = 0; i < numCourses; i++) inDegrees[i] = 0;
    for (vector<int>& p : prerequisites) inDegrees[p[0]]++;
    for (int i = 0; i < length; i++) isRemoved[i] = false;

    bool didRemove;

    do {
      didRemove = false;
      for (int i = 0; i < length; i++) {
        if (isRemoved[i]) continue;
        if (inDegrees[prerequisites[i][1]] != 0) continue;

        inDegrees[prerequisites[i][0]]--;
        isRemoved[i] = true;
        didRemove = true;
      }
    } while (didRemove);

    for (int i = 0; i < numCourses; i++) {
      if (inDegrees[i] != 0) return false;
    }

    return true;
  }
};