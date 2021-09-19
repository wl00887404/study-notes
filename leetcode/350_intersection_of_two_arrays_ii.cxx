#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums2.size() > nums1.size()) return intersect(nums2, nums1);
    
    unordered_map<int, int> frequencies;

    for (int& num : nums1) {
      if (!frequencies.count(num)) frequencies[num] = 0;
      frequencies[num]++;
    }

    vector<int> result;
    for (int num : nums2) {
      if (!frequencies.count(num)) continue;
      if (frequencies[num] == 0) continue;

      result.emplace_back(num);
      frequencies[num]--;
    }

    return result;
  }
};