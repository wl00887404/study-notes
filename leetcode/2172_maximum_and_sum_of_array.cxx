#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 2023/9/18
 * FIXME: 未完成
 */

/**
 * 題意：
 *   可以把 n 個數字分進 numSlots 組
 *   可以不依照順序分組
 *   每組最多 2 個值 ，可以是空的，也可以是 1 個值
 *   之後每組進行 AND 運算
 *   求和最大
 * 
 *   AND 運算是「數值 AND 組號」
 *   [1, 3] [4, 6] 是 1 & 1 + 3 & 1 + 4 & 2 + 6 & 2
 */

class Solution {
 public:
  int maximumANDSum(vector<int>& nums, int numSlots) {
    sort(nums.begin(), nums.end());
    int size = nums.size();
    if (size == 1) return nums[0];

    int singleCount = numSlots - (size + 1) / 2;
    int pairCount = size - singleCount;

    cout << pairCount << endl;
    int result = 0;

    int i = 0;
    for (; i < pairCount; i += 2) {
      result += nums[i] & nums[i + 1];
      cout << result << endl;
    }

    for (; i < size; i++) {
      result += nums[i];
    }

    return result;
  }
};