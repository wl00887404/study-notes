#include <unordered_map>
using namespace std;
/**
 * 1, 10                                , 100
 * 2, 11, 20                            , 101
 * 3, 12, 21, 30                        , 102
 * 4, 13, 22, 31, 40
 * 5, 14, 23, 32, 41, 50
 * 6, 15, 24, 33, 42, 51, 60
 * 7, 16, 25, 34, 43, 52,   , 70
 * 8, 17, 26, 35, 44, 53,   ,   , 80
 * 9, 18, 27, 36, 45, 54    ,   ,   , 90
 *    19, 28, 37, 46, 55
 *        29, 38, 47, 56
 *          , 39, 48, 57
 *              , 49, 58
 *                  , 59
 *
 * 1, 10, 100
 * 2, 11, 20, 101, 110, 200
 *
 */

class MySolution {
 public:
  int countLargestGroup(int n) {
    unordered_map<int, int> map;
    int maxGroupCount = 0;

    for (int i = 1; i <= n; i++) {
      int groupId = getGroupId(i);
      map[groupId]++;
      maxGroupCount = max(maxGroupCount, map[groupId]);
    }

    int result = 0;

    for (const pair<int, int>& p : map) {
      if (p.second == maxGroupCount) {
        result++;
      }
    }

    return result;
  }

  int getGroupId(int x) {
    int result = 0;

    while (x != 0) {
      result += x % 10;
      x /= 10;
    }

    return result;
  }
};

/**
 * 改一下追蹤最大 group 的方法
 */
class Solution {
 public:
  int countLargestGroup(int n) {
    unordered_map<int, int> map;
    int maxGroupCount = 0;
    int result = 1;

    for (int i = 1; i <= n; i++) {
      int groupId = getGroupId(i);
      map[groupId]++;

      if (maxGroupCount == map[groupId]) {
        // 有 group 的數量多到可以加入最大 group 了
        result++;
      }
      else if (maxGroupCount < map[groupId]) {
        // 有 group 的數量超過最大 group 了
        result = 1;
        maxGroupCount = map[groupId];
      }
    }

    return result;
  }

  int getGroupId(int x) {
    int result = 0;

    while (x != 0) {
      result += x % 10;
      x /= 10;
    }

    return result;
  }
};