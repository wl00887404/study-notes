#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;

    for (int& num : nums) {
      if (set.count(num)) return true;
      set.insert(num);
    }

    return false;
  }
};