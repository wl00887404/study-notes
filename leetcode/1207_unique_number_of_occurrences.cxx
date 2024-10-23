#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> map;
    unordered_set<int> set;

    for (int& i : arr) {
      map[i]++;
    }

    for (const pair<int, int>& p : map) {
      if (set.count(p.second)) return false;

      set.insert(p.second);
    }

    return true;
  }
};