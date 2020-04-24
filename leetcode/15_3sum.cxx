#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 混在一起 352 ms
 * 分成正負 256 ms
 * 改掉 unordered_map::begin() 196 ms
 * 
 * 太多元素會降低 unordered_map 的速度
 * boolean[] 試試看
 * 
 * TODO: 敢不敢再快一點
 */

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> results;

    if (length < 3) return results;

    unordered_map<int, int> positiveMap;
    vector<int> positiveNums;
    unordered_map<int, int> negativeMap;
    vector<int> negativeNums;
    int zeroLength = 0;

    for (int i = 0; i < length; i++) {
      if (nums[i] == 0) {
        zeroLength++;
        continue;
      }

      if (nums[i] > 0) {
        if (!positiveMap.count(nums[i])) {
          positiveMap[nums[i]] = 0;
          positiveNums.push_back(nums[i]);
        }

        positiveMap[nums[i]]++;
      } else {
        if (!negativeMap.count(nums[i])) {
          negativeMap[nums[i]] = 0;
          negativeNums.push_back(nums[i]);
        }

        negativeMap[nums[i]]++;
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

        if (negativeMap.count(complement)) {
          results.push_back({complement, 0, positiveNums[i]});
        }
      }

      if (positiveMap[positiveNums[i]] >= 2) {
        int complement = 0 - positiveNums[i] - positiveNums[i];

        if (negativeMap.count(complement)) {
          results.push_back({complement, positiveNums[i], positiveNums[i]});
        }
      }

      for (int j = i + 1; j < pLength; j++) {
        int complement = 0 - positiveNums[i] - positiveNums[j];

        if (negativeMap.count(complement)) {
          results.push_back({complement, positiveNums[i], positiveNums[j]});
        }
      }
    }

    for (int i = 0; i < nLength; i++) {
      if (hasZero && !isPositiveSmaller) {
        int complement = 0 - negativeNums[i];

        if (positiveMap.count(complement)) {
          results.push_back({complement, 0, negativeNums[i]});
        }
      }

      if (negativeMap[negativeNums[i]] >= 2) {
        int complement = 0 - negativeNums[i] - negativeNums[i];

        if (positiveMap.count(complement)) {
          results.push_back({complement, negativeNums[i], negativeNums[i]});
        }
      }

      for (int j = i + 1; j < nLength; j++) {
        int complement = 0 - negativeNums[i] - negativeNums[j];

        if (positiveMap.count(complement)) {
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