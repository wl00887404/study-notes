#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int length = nums.size();
    
    unordered_map<int, int> frequencies;
    vector<vector<int>> results;

    if (length < 3) return results;

    for (int i = 0; i < length; i++) {
      if (frequencies.count(nums[i])) {
        frequencies[nums[i]]++;
      } else {
        frequencies[nums[i]] = 1;
      }
    }

    unordered_map<int, int>::iterator it1 = frequencies.begin();
    unordered_map<int, int>::iterator end = frequencies.end();

    while (it1 != end) {
      if (it1->first == 0 && it1->second >= 3) {
        results.push_back({0, 0, 0});
      }

      unordered_map<int, int>::iterator it2 = it1;
      it2++;

      while (it2 != end) {
        int target = 0 - it1->first - it2->first;

        if (target == it1->first && it1->second >= 2) {
          results.push_back({target, target, it2->first});
        } else if (target == it2->first && it2->second >= 2) {
          results.push_back({target, target, it1->first});
        } else if (target > it1->first && target > it2->first &&
                   frequencies.count(target)) {
          results.push_back({it1->first, it2->first, target});
        }

        it2++;
      }

      it1++;
    }

    return results;
  }
} solution;

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  solution.threeSum(nums);

  return 0;
}