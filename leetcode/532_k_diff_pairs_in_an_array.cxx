#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    if (k == 0) return findDuplicate(nums);

    unordered_set<int> set;
    int result = 0;

    for (int& num : nums) {
      if (set.count(num)) continue;

      if (set.count(num - k)) result++;
      if (set.count(num + k)) result++;

      set.insert(num);
    }

    return result;
  }

  int findDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;
    int result = 0;
    for (int& num : nums) {
      map[num]++;

      if (map[num] == 2) result++;
    }

    return result;
  }
};