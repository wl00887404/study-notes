#include <iostream>
using namespace std;

/**
 * 每一個 pair 都是 A to B
 * 找一個點從來沒站在 A 點的
 */

class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_set<string> set;

    for (vector<string>& path : paths) {
      set.insert(path[1]);
    }

    for (vector<string>& path : paths) {
      set.erase(path[0]);
    }

    return *set.begin();
  }
};