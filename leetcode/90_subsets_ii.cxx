#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 一樣 subset
 * 但是不能有重複的組合
 * 像是 nums = [1, 2, 2]
 *
 * 結果是 [] [1] [2] [1, 2] [2, 2] [1, 2, 2]
 */

class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    for (const int& num : nums) {
      if (!map.count(num)) keys.push_back(num);
      map[num]++;
    }

    helper(0);

    return results;
  }

  void helper(int i) {
    if (i == keys.size()) {
      results.push_back(result);
      return;
    }

    helper(i + 1);

    const int& key = keys[i];
    int value = map[key];

    int j = value;
    while (j--) {
      result.push_back(key);
      helper(i + 1);
    }

    j = value;
    while (j--) result.pop_back();
  }

  unordered_map<int, int> map;
  vector<int> keys;
  vector<int> result;
  vector<vector<int>> results;
};