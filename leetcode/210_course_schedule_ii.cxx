#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 欸不對
 * 仔細一看
 * 它是有向圖吧
 *
 * 但是結果不一定是樹
 * 所以不用想建樹 + 找頭 + 找重複了
 *
 * 老樣子拔葉子
 * 先拔的最後上吧
 */

/**
 * 完成是完成了
 * 不過好慢 60 ms
 * TODO: 看看是不怎麼樣能比較快
 */

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    bool hasPrerequisites[numCourses];
    bool isRemoved[numCourses];
    int remain = numCourses;
    vector<int> result;

    for (int i = 0; i < numCourses; i++) {
      hasPrerequisites[i] = false;
      isRemoved[i] = false;
    }

    while (remain != 0) {
      // 紀錄目前有前置課程的課
      for (vector<int>& p : prerequisites) {
        if (isRemoved[p[1]]) continue;
        hasPrerequisites[p[0]] = true;
      }

      bool hasRemoved = false;
      // 將沒有前置課程的課上掉並且移除
      for (int i = 0; i < numCourses; i++) {
        if (isRemoved[i]) continue;
        if (hasPrerequisites[i]) {
          // 這個課程有前置
          // 復原 hasPrerequisites[i] 下一位
          hasPrerequisites[i] = false;
          continue;
        }

        hasRemoved = true;
        result.push_back(i);
        remain--;
        isRemoved[i] = true;
      }

      if (!hasRemoved) return {};
    }

    return result;
  }
};