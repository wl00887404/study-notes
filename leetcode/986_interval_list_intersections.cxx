#include <iostream>
#include <vector>

using namespace std;

/**
 * TODO: 最佳解好像不用 merge 耶
 */

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    int size = firstList.size() + secondList.size();

    vector<vector<int>*> merged;
    merged.resize(size);

    int last1 = firstList.size() - 1;
    int last2 = secondList.size() - 1;
    for (int i = size - 1; 0 <= i; i--) {
      // 沒有 secondList 了
      // 或是有 firstList 並且 firstList 比較大
      if (last2 < 0 || (last1 >= 0 && firstList[last1] > secondList[last2])) {
        merged[i] = &firstList[last1];
        last1--;
      } else {
        merged[i] = &secondList[last2];
        last2--;
      }
    }

    vector<vector<int>> result;

    // 現在尾端位置
    int end = (*merged[0])[1];

    for (int i = 1; i < size; i++) {
      vector<int>& current = *merged[i];

      // 有交集
      if (current[0] <= end) {
        result.push_back({current[0], min(current[1], end)});
      }

      end = max(end, current[1]);
    }

    return result;
  }
};