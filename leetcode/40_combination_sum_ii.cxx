#include <algorithm>
#include <iostream>
#include <vector>

#include "./log.cxx"
using namespace std;

class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> results;
    vector<int> result;

    sort(candidates.begin(), candidates.end());
    combinationSum2(results, candidates, target, 0, result);

    return results;
  }

  void combinationSum2(vector<vector<int>>& results, vector<int>& candidates,
                       int target, int i, vector<int>& result) {
    if (target == 0) return results.push_back(result);

    int length = candidates.size();

    for (int j = i; j < length && target >= candidates[j]; j++) {
      result.push_back(candidates[j]);
      combinationSum2(results, candidates, target - candidates[j], j + 1,
                      result);

      while (j + 1 < length && candidates[j] == candidates[j + 1]) j++;

      result.pop_back();
    }
  }
} solution;

int main() {
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;

  vector<vector<int>> results = solution.combinationSum2(candidates, target);

  log(results);

  return 0;
}