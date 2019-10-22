#include <iostream>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/articles/stone-game/
 *
 * 如果 Alex 取 1st
 * 那 Alex 必定可以取 3rd, 5th, 7th...
 * 同樣的 Alex 如果取 last
 * 那也必定可以取 2nd, 4th, 6th...
 * Alex 的策略很簡單，
 * 就是先比較奇數項總和與偶數像總和，取頭或尾，
 * 接著就跟 Lee 取，
 * Lee 取頭跟著取頭， Lee 取尾跟著取尾，
 * 完全躺贏
 */

class Solution {
 public:
  bool stoneGame(vector<int> &piles) { return true; }
};