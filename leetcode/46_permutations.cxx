#include <iostream>
#include <vector>
using namespace std;

/**
 * 是很常遇到的排列組合題！！
 * 欸欸欸直接傳 STL 容器 都不是傳址耶！！好扯喔！！
 *
 * dae35f4: 遞迴法 32ms 哭了
 *
 * 不要閉門造車比較好
 * Steinhaus–Johnson–Trotter algorithm:
 * https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm
 * Heap's algorithm:
 *   https://en.wikipedia.org/wiki/Heap's_algorithm
 *
 * | nums | k   | i   |            |
 * | ---- | --- | --- | ---------- |
 * | 1 2  | 2   |     |            |
 * | 2 1  | 2   | 0   | swap(0, 1) |
 *
 * | nums  | k   | i   |            |
 * | ----- | --- | --- | ---------- |
 * | 1 2 3 | 3   |     |            |
 * | 2 1 3 | 2   | 0   | swap(0, 1) |
 * | 3 1 2 | 3   | 0   | swap(0, 2) |
 * | 1 3 2 | 2   | 0   | swap(0, 1) |
 * | 2 3 1 | 3   | 1   | swap(0, 2) |
 * | 3 2 1 | 2   | 0   | swap(0, 1) |
 *
 * 固定後面 交換前面
 * 偶數項前後互換 奇數項首尾互換
 */

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> results;

    permute(results, nums, length);

    return results;
  }
  void permute(vector<vector<int>>& results, vector<int>& nums, int k) {
    if (k == 1) {
      results.push_back(nums);
    } else {
      permute(results, nums, k - 1);

      for (int i = 0; i < k - 1; i++) {
        if (k % 2 == 0) {
          swap(nums[i], nums[k - 1]);
        } else {
          swap(nums[0], nums[k - 1]);
        }

        permute(results, nums, k - 1);
      }
    }
  }
} solution;

int main() {
  vector<int> nums = {1, 2, 3, 4};
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
