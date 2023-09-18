#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1;
    unordered_set<int> set2;

    for (int& num : nums1) set1.insert(num);
    for (int& num : nums2) set2.insert(num);

    vector<vector<int>> result(2);

    for (const int& num : set1) {
      if (set2.count(num)) continue;
      result[0].push_back(num);
    }

    for (const int& num : set2) {
      if (set1.count(num)) continue;
      result[1].push_back(num);
    }

    return result;
  }
};