#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * Quickselect (Hoare's selection algorithm)
 *   感覺沒有比較快
 */

/**
 * 竟然有 priority_queue 耶
 * priority_queue<pair<int, int>> pq;
 * for (auto x : hmap) pq.push({x.second, x.first});
 * vector<int> ans;
 * while (k--) {
 *   ans.push_back(pq.top().second);
 *   pq.pop();
 * }
 * 
 * return ans;
 */

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    if (k == nums.size()) return nums;

    unordered_map<int, int> frequencies;
    for (int& num : nums) {
      if (!frequencies.count(num)) frequencies[num] = 0;
      frequencies[num]++;
    }

    int max = 0;
    unordered_map<int, vector<int>> inverseMapping;
    for (const pair<int, int>& pair : frequencies) {
      if (pair.second > max) max = pair.second;
      inverseMapping[pair.second].push_back(pair.first);
    }

    vector<int> result;
    int i = 0;
    while (k != 0) {
      for (int& j : inverseMapping[max - i]) {
        result.push_back(j);
        k--;
      }
      i++;
    }

    return result;
  }
};