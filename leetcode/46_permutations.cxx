#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 是很常遇到的排列組合題！！
 * 欸欸欸直接傳 STL 容器 都不是傳址耶！！好扯喔！！
 *
 * dae35f4: 遞迴法 32ms 哭了
 */

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> results;

    if (length == 0) return results;

    for (int i = 0; i < length; i++) {
      auto recursiveResults = permute(nums, {}, i);

      results.insert(results.end(), recursiveResults.begin(),
                     recursiveResults.end());
    }

    return results;
  }
  vector<vector<int>> permute(vector<int> nums, vector<int> tempResult,
                              int index) {
    tempResult.push_back(nums[index]);
    nums.erase(nums.begin() + index);
    int length = nums.size();

    if (length == 0) return {tempResult};

    vector<vector<int>> results;

    for (int i = 0; i < length; i++) {
      auto recursiveResults = permute(nums, tempResult, i);

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
