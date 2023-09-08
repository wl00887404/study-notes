
#include <iostream>
#include <vector>

using namespace std;

/**
 * 在一個已排序的陣列移除出現太多次的元素
 * 一個元素最多出現兩次
 * 要把多出來的元素 shift 到後面
 */
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int copyIndex = 1;
    int comparedIndex = 0;
    int frequency = 1;
    int size = nums.size();

    for (int i = 1; i < size; i++) {
      if (nums[i] == nums[comparedIndex]) {
        frequency++;

        // 出現兩次以上了，什麼都不用做
        if (frequency > 2) continue;
      } else {
        // 新數字登場
        comparedIndex = i;
        frequency = 1;
      }

      nums[copyIndex] = nums[i];
      copyIndex++;
    }

    return copyIndex;
  }
};