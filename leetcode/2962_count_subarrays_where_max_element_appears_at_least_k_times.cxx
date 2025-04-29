#include <iostream>
#include <vector>
using namespace std;

/**
 * 最大的元素必須出現 k 次，找出所有符合的子陣列數量
 */

/**
 * 計算的方式類似 2444
 *
 *         0  1  2  3  4  5
 * nums = [1, 3, 2, 3, 2, 3], k = 2
 * maxPositions = [1, 3,  5]
 *
 * 1 (3 2 3)
 *   (3 2 3) 2
 * 1 (3 2 3) 2
 *
 * 1 3 2 (3 2 3)
 *   3 2 (3 2 3)
 *     2 (3 2 3)
 *       (3 2 3)
 */

class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    int max = 0;
    vector<int> maxPositions;
    int size = nums.size();
    long long result = 0;

    for (int i = 0; i < size; i++) {
      if (nums[i] == max) {
        maxPositions.push_back(i);
      } else if (nums[i] > max) {
        max = nums[i];
        maxPositions.clear();
        maxPositions.push_back(i);
      }
    }

    int pSize = maxPositions.size();
    for (int i = 0; i < pSize; i++) {
      int j = i + k - 1;
      if (j >= pSize) break;

      int left = 0;
      int right = j + 1 < pSize ? maxPositions[j + 1] : size;

      result +=
          (long long)(maxPositions[i] - left + 1) * (right - maxPositions[j]);
    }

    return result;
  }
};
