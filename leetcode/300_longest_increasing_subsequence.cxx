#include <math.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 這題是 hard 吧
 * 難到爆

/**
 * 用我的邏輯寫吧
 * 序列產生很簡單，就要跟不要
 * 要的話，長度 + 1 ，最小值為它
 * 不要的話，長度不變，不改變最小值
 *
 * 優化方向呢？
 * http://web.ntnu.edu.tw/~algo/Subsequence.html
 *
 * cache 的方法寫出來了
 * O(n^2) 死去
 */

/**
 * 發現 sort 完後找 LCS 的做法
 */

/**
 * binary search 解
 *
 * [0,           2,     6,        9,           11,    15]
 * [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
 *
 * binary search 找 insert index
 *
 * 0 直接 push 不須取代任何人
 * [0]
 *
 * 8 直接 push 不須取代任何人
 * [0]
 * [0, 8]
 *
 * 4 取代 8
 * [0]
 * [0, 4]
 *
 * 12 直接 push 不須取代任何人
 * [0]
 * [0, 4]
 * [0, 4, 12]
 *
 * 2 取代 4
 * [0]
 * [0, 2]
 * [0, 4, 12]
 *
 * 10 取代 12
 * [0]
 * [0, 2]
 * [0, 2, 10]
 *
 * 6 取代 10
 * [0]
 * [0, 2]
 * [0, 2, 6]
 *
 * 14 直接 push 不須取代任何人
 * [0]
 * [0, 2]
 * [0, 2, 6]
 * [0, 2, 6, 14]
 *
 * 1 取代 2
 * [0]
 * [0, 1]
 * [0, 2, 6]
 * [0, 2, 6, 14]
 *
 * 9 取代 14
 * [0]
 * [0, 1]
 * [0, 2, 6]
 * [0, 2, 6, 9]
 *
 * 5 直接 push 不取代任何人
 * [0]
 * [0, 1]
 * [0, 1, 5]
 * [0, 2, 6, 9]
 *
 * 13 直接 push 不取任何人
 * [0]
 * [0, 1]
 * [0, 1, 5]
 * [0, 2, 6, 9]
 * [0, 2, 6, 9, 13]
 *
 * 3 取代 5
 * [0]
 * [0, 1]
 * [0, 1, 3]
 * [0, 2, 6, 9]
 * [0, 2, 6, 9, 13]
 *
 * 11 取代 13
 * [0]
 * [0, 1]
 * [0, 1, 3]
 * [0, 2, 6, 9]
 * [0, 2, 6, 9, 11]
 *
 * 7 取代 9
 * [0]
 * [0, 1]
 * [0, 1, 3]
 * [0, 1, 3, 7]
 * [0, 2, 6, 9, 11]
 *
 * 15 直接 push 不取代任何人
 * [0]
 * [0, 1]
 * [0, 1, 3]
 * [0, 2, 6, 7]
 * [0, 2, 6, 9, 11, 15]
 */

class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<double> lasts(nums.size(), INFINITY);  // 每一長度的結尾
    int result = 0;

    for (int& num : nums) {
      int insertPosition = binarySearchForInsertPosition(lasts, num);
      if (insertPosition > result) result = insertPosition;
      lasts[insertPosition] = num;
    }

    return result + 1;
  }

  int binarySearchForInsertPosition(vector<double>& lasts, int& target) {
    int left = 0;
    int right = lasts.size();

    while (left < right) {
      int mid = (left + right) / 2;

      if (lasts[mid] == target) return mid;

      if (lasts[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }
} solution;

class LCSSolution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> distinctNums = distinct(nums);
    sort(distinctNums.begin(), distinctNums.end());

    return LCS(nums, distinctNums);
  }

 private:
  int LCS(vector<int>& nums1, vector<int>& nums2) {
    int length1 = nums1.size();
    int length2 = nums2.size();
    int dp[length1 + 1][length2 + 1];

    for (int i = 0; i <= length1; i++) dp[i][0] = 0;
    for (int j = 0; j <= length2; j++) dp[0][j] = 0;

    for (int i = 1; i <= length1; i++) {
      for (int j = 1; j <= length2; j++) {
        if (nums1[i - 1] == nums2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[length1][length2];
  }

  vector<int> distinct(vector<int>& nums) {
    vector<int> result;
    unordered_set<int> set;

    for (int& num : nums) {
      if (set.count(num)) continue;
      result.push_back(num);
      set.insert(num);
    }

    return result;
  }
};

// FIXME: 我不知道怎麼傳 2D array 當參數
class RecursionSolution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int length = nums.size();
    int cacheLength = length * length;
    int cache[cacheLength];  // current 位置 * length + min 位置

    for (int i = 0; i < cacheLength; i++) cache[i] = 0;

    return lengthOfLIS(nums, 0, -1, cache, length);
  }

  int lengthOfLIS(vector<int>& nums, int i, int j, int* cache, int& length) {
    if (i >= length) return 0;
    if (j != -1 && cache[i * length + j]) return cache[i * length + j];

    int notSelectedResult = lengthOfLIS(nums, i + 1, j, cache, length);
    if (j != -1 && nums[j] >= nums[i]) return notSelectedResult;

    int selectedResult = 1 + lengthOfLIS(nums, i + 1, i, cache, length);
    int result = max(notSelectedResult, selectedResult);

    if (j != -1) cache[i * length + j] = result;

    return result;
  }
};

int test() { return 2; }

int main() {
  vector<double> nums = {0, 2, 5, 8, 10};

  // cout << solution.lengthOfLIS(nums) << endl;

  return 0;
}
