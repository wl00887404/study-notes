#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * 不難
 * 只是遞迴時傳 vector 會複製
 * 寫遞迴時要特別注意一下
 */

/**
 * 2 3 6 7 : 7
 *
 * [] + 2:
 *   7 []
 *   5 [2]
 *   3 [2, 2]
 *   1 [2, 2, 2] (x)
 *
 * [] + 3:
 *   7 []
 *   4 [3]
 *   1 [3, 3] (x)
 * [2] + 3:
 *   5 [2]
 *   2 [2, 3] (x)
 * [2, 2] + 3:
 *   3 [2, 2]
 *   0 [2, 2, 3] push
 *
 * [] + 6:
 *   7 []
 *   1 [6] (x)
 * [3] + 6:
 *   4 [3] (x)
 * [2] + 6:
 *   5 [2] (x)
 * [2, 2] + 6:
 *   3 [2, 2] (x)
 *
 * [] + 7 :
 *    0 [7] push
 */

class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    vector<int> result;

    sort(candidates.begin(), candidates.end());
    combinationSum(results, candidates, target, 0, result);

    return results;
  }

  void combinationSum(vector<vector<int>>& results, vector<int>& candidates,
                      int target, int i, vector<int>& result) {
    if (target == 0) return results.push_back(result);
    if (i == candidates.size()) return;

    combinationSum(results, candidates, target, i + 1, result);

    int j = 0;

    while (target >= candidates[i]) {
      j++;
      target -= candidates[i];
      result.push_back(candidates[i]);
      combinationSum(results, candidates, target, i + 1, result);
    }

    while (j--) result.pop_back();
  }
} solution;

int main() {
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;

  vector<vector<int>> results = solution.combinationSum(candidates, target);

  return 0;
}