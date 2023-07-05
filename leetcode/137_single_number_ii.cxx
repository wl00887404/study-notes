#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 要想 Time complexity O(n) + Space complexity O(1)
 * 就看怎麼處理三個數字的問題
 */

/**
 * 不行，完全想不到
 */

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_set<int> set;
    long long result = 0;

    for (const int& num : nums) {
      if (set.count(num)) {
        result -= num;
      } else {
        result += num;
        result += num;
        set.insert(num);
      }
    }

    return result / 2;
  }
};