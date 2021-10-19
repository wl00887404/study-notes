#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 沒什麼料的題目
 */

class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;

    int size1 = nums1.size();
    for (int i = 0; i < size1; i++) map[nums1[i]] = i;

    int size2 = nums2.size();
    for (int i = 0; i < size2; i++) {
      int& target = nums2[i];
      if (!map.count(target)) continue;

      int& nums1Index = map[target];
      nums1[nums1Index] = -1;
      for (int j = i + 1; j < size2; j++) {
        if (nums2[j] < target) continue;
        nums1[nums1Index] = nums2[j];
        break;
      }
    }

    return nums1;
  }
};