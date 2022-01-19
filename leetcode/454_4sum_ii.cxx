#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 老樣子跟 target sum 一樣耶
 * 總覺得就是類似背包問題的題目
 */

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    unordered_map<int, int> map1;
    unordered_map<int, int> map2;
    unordered_map<int, int> map3;

    for (int& num : nums1) {
      map1[num]++;
    }

    for (int& num : nums2) {
      for (const pair<int, int>& p : map1) {
        map2[p.first + num] += p.second;
      }
    }

    for (int& num : nums3) {
      for (const pair<int, int>& p : map2) {
        map3[p.first + num] += p.second;
      }
    }

    int result = 0;

    for (int& num : nums4) {
      if (map3.count(-1 * num)) {
        result += map3[-1 * num];
      }
    }

    return result;
  }
};