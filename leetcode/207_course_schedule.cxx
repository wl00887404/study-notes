#include <iostream>
#include <vector>
using namespace std;

/**
 * 有向圖偵測有沒有環
 * 分支要怎麼處理
 */

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    /**
     * type prerequisite = [此課程, 先修課程]
     * type prerequisites = prerequisite[]
     */

    bool isRoot[numCourses];
    bool isLeaf[numCourses];
    bool isDisabled[numCourses];
    for (int i = 0; i < numCourses; i++) isDisabled[i] = false;

    int disabledCount = 0;

    while (true) {
      int nextDisableCount = 0;
      for (int i = 0; i < numCourses; i++) {
        isRoot[i] = true;
        isLeaf[i] = true;
      }
      // 跑過目前有效的連結，找出所有根、葉
      for (vector<int>& p : prerequisites) {
        if (isDisabled[p[0]] || isDisabled[p[1]]) continue;
        // 如果課程被連結，那它就不是根
        isRoot[p[0]] = false;
        // 如果課程連結別人，那它就不是葉
        isLeaf[p[1]] = false;
      }
      for (int i = 0; i < numCourses; i++) {
        // 此課程必須連接別人且被連接
        // 才不會被移除
        if (!isRoot[i] && !isLeaf[i]) continue;
      
        nextDisableCount++;
        isDisabled[i] = true;
      }

      if(disabledCount == nextDisableCount) break;

      disabledCount = nextDisableCount;
    }

    return disabledCount == numCourses;
  }
};