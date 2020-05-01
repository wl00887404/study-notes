#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * 混在一起 352 ms
 * 分成正負 256 ms
 * 改掉 unordered_map::begin 196 ms
 *
 * wiki 有 T1 解
 * https://zh.wikipedia.org/wiki/3SUM
 *
 * TODO: 敢不敢再快一點
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
} solution;

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> results = solution.threeSum(nums);

  log(results);

  return 0;
}