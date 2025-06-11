#include <iostream>
#include <vector>
using namespace std;

/**
 * queries 是 pair，begin 與 end 都是 included
 * 每次 query 讓範圍內的 nums 都 -1
 * 問查詢完能不能讓 nums 歸零
 */

/**
 * 實際操作一定有解，但有沒有方法可以直接做範圍的查詢
 * 譬如說 i = 1，直接知道有打中幾個範圍
 */

/**
 * 下去買個蘿蔔絲餅（巷仔口蘿蔔絲餅遼寧店）就想通 diffent array 在幹嘛了
 * diff = [0, 0 ,0 ,0, 0]
 * 新增範圍 [1, 3] => diff = [0, 1, 0, 0, -1, 0]
 * 表示從 diff[1] 開始就新增 1，到 diff[4] 增益結束
 */

class Solution {
 public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int size = nums.size();
    vector<int> diff(size, 0);

    for (const vector<int>& q : queries) {
      const int& begin = q[0];
      int end = q[1] + 1;

      diff[begin]++;
      if (end < size) diff[end]--;
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
      sum += diff[i];

      if (sum < nums[i]) return false;
    }

    return true;
  }
};