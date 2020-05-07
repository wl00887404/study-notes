#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<int, int> map;
    int length = nums.size();

    for (int i = 0; i < length; i++) {
      map[nums[i]]++;

      if (map[nums[i]] > length / 2) return nums[i];
    }

    return -1;
  }
};