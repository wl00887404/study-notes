#include <iostream>
#include <vector>

using namespace std;

/**
 * 先統計一個連續的長度
 * 0 用負的表示？
 * 如果是 -1 ，表示可以斷開兩邊加起來
 * 或是正數旁邊有負數，可以直接採用
 */
class Solution {
 public:
  int longestSubarray(vector<int>& nums) {
    int size = nums.size();
    vector<int> values;

    int value = nums[0] ? 1 : -1;
    for (int i = 1; i < size; i++) {
      int num = nums[i] ? 1 : -1;
      if (value * nums[i] > 0) {
        // 同方向
        value += num;
      } else {
        values.push_back(value);
        value = num;
      }
    }
    values.push_back(value);

    int result = 0;
    size = values.size();

    // 沒有負數可以捨棄
    if (size == 1) {
      result = max(result, values[0] - 1);
      return result;
    }

    for (int i = 0; i < size; i++) {
      if (values[i] > 0) {
        // 自己不用捨棄
        result = max(result, values[i]);
      } else if (values[i] == -1 && 0 < i && i < size - 1) {
        // -1 的空格可以捨棄，讓兩邊連起來
        result = max(result, values[i - 1] + values[i + 1]);
      }
    }

    return result;
  }
};