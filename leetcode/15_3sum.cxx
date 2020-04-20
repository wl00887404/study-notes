#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 混在一起 352 ms
 * 分成正負 256 ms
 * 
 * TODO: 太慢了吧
 */

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int length = nums.size();
    vector<vector<int>> results;

    if (length < 3) return results;

    unordered_map<int, int> positiveMap;
    unordered_map<int, int> negativeMap;
    int zeroLength = 0;

    for (int i = 0; i < length; i++) {
      if (nums[i] == 0) {
        zeroLength++;
        continue;
      }

      if (nums[i] > 0) {
        if (positiveMap.count(nums[i])) {
          positiveMap[nums[i]]++;
        } else {
          positiveMap[nums[i]] = 1;
        }
      } else {
        if (negativeMap.count(nums[i])) {
          negativeMap[nums[i]]++;
        } else {
          negativeMap[nums[i]] = 1;
        }
      }
    }

    int pLength = positiveMap.size();
    int nLength = negativeMap.size();

    if (zeroLength >= 3) results.push_back({0, 0, 0});

    if (pLength == 0 || nLength == 0) return results;

    bool isPositiveSmaller = pLength < nLength;

    unordered_map<int, int>::iterator begin1 = positiveMap.begin();
    unordered_map<int, int>::iterator end = positiveMap.end();

    while (begin1 != end) {
      if (zeroLength != 0 && isPositiveSmaller) {
        int complement = 0 - begin1->first;

        if (negativeMap.count(complement)) {
          results.push_back({complement, 0, begin1->first});
        }
      }

      if (begin1->second >= 2) {
        int complement = 0 - begin1->first - begin1->first;

        if (negativeMap.count(complement)) {
          results.push_back({complement, begin1->first, begin1->first});
        }
      }

      unordered_map<int, int>::iterator begin2 = begin1;
      begin2++;

      while (begin2 != end) {
        int complement = 0 - begin1->first - begin2->first;

        if (negativeMap.count(complement)) {
          results.push_back({complement, begin1->first, begin2->first});
        }

        begin2++;
      }

      begin1++;
    }

    begin1 = negativeMap.begin();
    end = negativeMap.end();

    while (begin1 != end) {
      if (zeroLength != 0 && !isPositiveSmaller) {
        int complement = 0 - begin1->first;

        if (positiveMap.count(complement)) {
          results.push_back({begin1->first, 0, complement});
        }
      }

      if (begin1->second >= 2) {
        int complement = 0 - begin1->first - begin1->first;

        if (positiveMap.count(complement)) {
          results.push_back({begin1->first, begin1->first, complement});
        }
      }

      unordered_map<int, int>::iterator begin2 = begin1;
      begin2++;

      while (begin2 != end) {
        int complement = 0 - begin1->first - begin2->first;

        if (positiveMap.count(complement)) {
          results.push_back({begin1->first, begin2->first, complement});
        }

        begin2++;
      }

      begin1++;
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