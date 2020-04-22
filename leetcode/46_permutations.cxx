#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 是很常遇到的排列組合題！！
 * 欸欸欸直接傳 STL 容器 都不是傳址耶！！好扯喔！！
 */

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> results;

    if (length == 0) return results;

    for (int i = 0; i < length; i++) {
      auto recursiveResults = permute(nums, {}, {}, nums[i]);

      results.insert(results.end(), recursiveResults.begin(),
                     recursiveResults.end());
    }

    return results;
  }
  vector<vector<int>> permute(vector<int>& nums, unordered_set<int> usedNums,
                              vector<int> tempResult, int value) {
    int length = nums.size();
    usedNums.insert(value);
    tempResult.push_back(value);

    if (tempResult.size() == length) return {tempResult};

    vector<vector<int>> results;

    for (int i = 0; i < length; i++) {
      if (usedNums.count(nums[i])) continue;

      auto recursiveResults = permute(nums, usedNums, tempResult, nums[i]);

      results.insert(results.end(), recursiveResults.begin(),
                     recursiveResults.end());
    }

    return results;
  }
} solution;

int main() {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> results = solution.permute(nums);

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
