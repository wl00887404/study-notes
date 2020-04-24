#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
/**
 * 不難
 * 只是遞迴時傳 vector 會複製
 * dfs 應該可以刪掉 研究一下
 *
 * TODO: 把 result 改成 & result
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

    sort(candidates.begin(), candidates.end());
    combinationSum(results, candidates, target, 0, {});

    return results;
  }

  void combinationSum(vector<vector<int>>& results, vector<int>& candidates,
                      int target, int i, vector<int> result) {
    int length = candidates.size();

    while (target >= candidates[i]) {
      // cout << target << " | ";
      // cout << candidates[i] << " | ";
      // cout << "[ ";
      // for (int j = 0; j < result.size(); j++) {
      //   cout << result[j];
      //   if (j != result.size() - 1) cout << ", ";
      // }
      // cout << " ]" << endl;

      if (i + 1 < length) {
        combinationSum(results, candidates, target, i + 1, result);
      }

      target -= candidates[i];
      result.push_back(candidates[i]);

      if (target == 0) results.push_back(result);
    }
  }
} solution;

int main() {
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;

  vector<vector<int>> results = solution.combinationSum(candidates, target);

  cout << "{" << endl;
  for (int i = 0; i < results.size(); i++) {
    cout << "  { ";
    for (int j = 0; j < results[i].size(); j++) {
      cout << results[i][j];
      if (j != results[i].size() - 1) cout << ", ";
    }
    cout << " }," << endl;
  }
  cout << "}" << endl;

  return 0;
}