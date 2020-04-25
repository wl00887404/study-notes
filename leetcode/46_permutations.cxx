#include <iostream>
#include <vector>
using namespace std;

/**
 * #recommend:
 *   是很常遇到的排列組合題！！
 *
 * dae35f4: 遞迴法 32 ms 哭了
 *
 * 欸欸欸 STL 容器不是傳址耶！！好扯喔！！
 * 遞迴法不會比較慢
 * 是dfs 的寫法沒寫好 = =
 * 
 * 不要閉門造車:
 * Steinhaus–Johnson–Trotter algorithm:
 *   https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm
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
 *
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
    if (k == 1) return results.push_back(nums);

    permute(results, nums, k - 1);

    for (int i = 0; i < k - 1; i++) {
      int swapIndex = k % 2 ? 0 : i;

      swap(nums[swapIndex], nums[k - 1]);
      permute(results, nums, k - 1);
    }
  }
} solution;

class RecursiveSolution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> results;
    bool seen[nums.size()];
    vector<int> result;

    permute(results, seen, nums, result);

    return results;
  }

  void permute(vector<vector<int>>& results, bool seen[], vector<int>& nums,
               vector<int>& result) {
    int length = nums.size();

    if (result.size() == length) return results.push_back(result);

    for (int i = 0; i < length; i++) {
      if (seen[i]) continue;

      seen[i] = true;
      result.push_back(nums[i]);
      permute(results, seen, nums, result);
      seen[i] = false;
      result.pop_back();
    }
  };
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  vector<vector<int>> results = solution.permute(nums);

  return 0;
}
