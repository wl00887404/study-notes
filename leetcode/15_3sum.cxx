#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * 混在一起 352 ms
 * 分成正負 256 ms
 * 改掉 unordered_map::begin 172 ms
 *
 * wiki 有 T1 解
 * https://zh.wikipedia.org/wiki/3SUM
 *
 * -4 -1 -1 0 1 2
 *  ^  ^        ^    sum = -3 | 太小了， mid 往右移
 * -4 -1 -1 0 1 2
 *  ^       ^   ^    sum = -2
 * -4 -1 -1 0 1 2
 *  ^         ^ ^    sum = -1
 * -4 -1 -1 0 1 2
 *     ^  ^     ^    sum =  0 | 找到一組！
 * -4 -1 -1 0 1 2
 *     ^      ^ ^    sum =  2 | 太大了， right 往左移， 可惜左邊沒有了
 * -4 -1 -1 0 1 2
 *
 * left > 0 表示右側全是正數
 * 因此不可能再有解了
 */

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> results;

    if (length < 3) return results;

    unordered_set<int> onceNums;
    unordered_set<int> twiceNums;
    vector<int> positiveNums;
    vector<int> negativeNums;
    int zeroLength = 0;

    for (int i = 0; i < length; i++) {
      if (nums[i] == 0) {
        zeroLength++;
        continue;
      }

      if (!onceNums.count(nums[i])) {
        onceNums.insert(nums[i]);

        if (nums[i] > 0) {
          positiveNums.push_back(nums[i]);
        } else {
          negativeNums.push_back(nums[i]);
        }

        continue;
      }

      if (!twiceNums.count(nums[i])) twiceNums.insert(nums[i]);
    }

    int positiveLength = positiveNums.size();
    int negativeLength = negativeNums.size();

    if (zeroLength >= 3) results.push_back({0, 0, 0});

    if (positiveLength == 0 || negativeLength == 0) return results;

    bool isPositiveSmaller = positiveLength < negativeLength;
    bool hasZero = zeroLength > 0;

    for (int i = 0; i < positiveLength; i++) {
      if (hasZero && isPositiveSmaller) {
        int complement = 0 - positiveNums[i];

        if (onceNums.count(complement)) {
          results.push_back({complement, 0, positiveNums[i]});
        }
      }

      int j = twiceNums.count(positiveNums[i]) ? i : i + 1;

      for (; j < positiveLength; j++) {
        int complement = 0 - positiveNums[i] - positiveNums[j];

        if (onceNums.count(complement)) {
          results.push_back({complement, positiveNums[i], positiveNums[j]});
        }
      }
    }

    for (int i = 0; i < negativeLength; i++) {
      if (hasZero && !isPositiveSmaller) {
        int complement = 0 - negativeNums[i];

        if (onceNums.count(complement)) {
          results.push_back({complement, 0, negativeNums[i]});
        }
      }

      int j = twiceNums.count(negativeNums[i]) ? i : i + 1;

      for (; j < negativeLength; j++) {
        int complement = 0 - negativeNums[i] - negativeNums[j];

        if (onceNums.count(complement)) {
          results.push_back({complement, negativeNums[i], negativeNums[j]});
        }
      }
    }

    return results;
  }
};

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> results;

    if (length < 3) return results;

    sort(nums.begin(), nums.end());

    for (int left = 0; left < length - 2; left++) {
      if (left > 0 && nums[left] == nums[left - 1]) continue;

      // 最小會比 0 大
      if (nums[left] + nums[left + 1] + nums[left + 2] > 0) break;
      // 最大會比 0 小
      if (nums[left] + nums[length - 2] + nums[length - 1] < 0) continue;

      int mid = left + 1;
      int right = length - 1;

      while (mid < right) {
        int sum = nums[left] + nums[mid] + nums[right];

        if (sum == 0) results.push_back({nums[left], nums[mid], nums[right]});

        if (sum <= 0) {
          while (mid < right && nums[mid] == nums[mid + 1]) mid++;

          mid++;
        }

        if (sum >= 0) {
          while (mid < right && nums[right - 1] == nums[right]) right--;

          right--;
        }
      }
    }

    return results;
  }
} solution;

int main() {
  // vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<int> nums = {-2, 0, 0, 2, 2};
  vector<vector<int>> results = solution.threeSum(nums);

  log(results);

  return 0;
}