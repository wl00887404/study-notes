#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    int length = nums.size();

    for (int i = 0; i < length; i++) {
      int x = nums[i];
      int rest = target - x;
      
      if (map.count(rest)) return {i, map[rest]};

      map[nums[i]] = i;
    }

    return {};
  }
};