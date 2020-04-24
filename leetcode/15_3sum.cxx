#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * 混在一起 352 ms
 * 分成正負 256 ms
 * 改掉 unordered_map::begin 196 ms
 *
 * 應該是太多元素會降低 unordered_map 的速度
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

      if (!twiceNums.count(nums[i])) {
        twiceNums.insert(nums[i]);
      }
    }

    int pLength = positiveNums.size();
    int nLength = negativeNums.size();

    if (zeroLength >= 3) results.push_back({0, 0, 0});

    if (pLength == 0 || nLength == 0) return results;

    bool isPositiveSmaller = pLength < nLength;
    bool hasZero = zeroLength > 0;

    for (int i = 0; i < pLength; i++) {
      if (hasZero && isPositiveSmaller) {
        int complement = 0 - positiveNums[i];

        if (onceNums.count(complement)) {
          results.push_back({complement, 0, positiveNums[i]});
        }
      }

      if (twiceNums.count(positiveNums[i])) {
        int complement = 0 - positiveNums[i] - positiveNums[i];

        if (onceNums.count(complement)) {
          results.push_back({complement, positiveNums[i], positiveNums[i]});
        }
      }

      for (int j = i + 1; j < pLength; j++) {
        int complement = 0 - positiveNums[i] - positiveNums[j];

        if (onceNums.count(complement)) {
          results.push_back({complement, positiveNums[i], positiveNums[j]});
        }
      }
    }

    for (int i = 0; i < nLength; i++) {
      if (hasZero && !isPositiveSmaller) {
        int complement = 0 - negativeNums[i];

        if (onceNums.count(complement)) {
          results.push_back({complement, 0, negativeNums[i]});
        }
      }

      if (twiceNums.count(negativeNums[i])) {
        int complement = 0 - negativeNums[i] - negativeNums[i];

        if (onceNums.count(complement)) {
          results.push_back({complement, negativeNums[i], negativeNums[i]});
        }
      }

      for (int j = i + 1; j < nLength; j++) {
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

  cout << "{ " << endl;
  for (int i = 0; i < results.size(); i++) {
    cout << "  { ";
    for (int j = 0; j < results[i].size(); j++) {
      cout << results[i][j];
      if (j != results[i].size() - 1) {
        cout << ", ";
      }
    }
    cout << " }," << endl;
  }
  cout << "}" << endl;

  return 0;
}