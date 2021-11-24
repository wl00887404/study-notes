#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 如果兩個位置標號一樣就可以連線
 * 每個位置只能連一次
 *
 * 最佳解一定是每個人跟對面連結
 */

/**
 * Hint1 說是 dp 題
 * 可以用 dp[i][j] 表示 A[i:] B[j:]
 */

/**
 * 幹你娘完全想不懂那個 dp
 * 還是遞迴解一解就好
 */

class Solution {
 public:
  int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = &nums1;
    size1 = nums1.size();
    size2 = nums2.size();
    int array[size1 * size2];
    cache = array;

    for (int i = size1 * size2 - 1; 0 <= i; i--) array[i] = -1;
    for (int j = 0; j < size2; j++) {
      positionsByNum2[nums2[j]].push_back(j);
    }

    return helper(0, 0);
  }

  // 要找第一個大於等於它的元素（包含自己）
  int binarySearch(vector<int>& positions, int& j) {
    int size = positions.size();
    int left = 0;
    int right = size;

    while (left < right) {
      int mid = (left + right) / 2;

      if (positions[mid] == j) return positions[mid];
      if (positions[mid] > j) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    if (left == size) return -1;

    return positions[left];
  }

  int linearSearch(vector<int>& positions, int& j) {
    for (int& position : positions) {
      if (position < j) continue;
      return position;
    }

    return -1;
  }

 private:
  vector<int>* nums1;
  int size1;
  int size2;
  unordered_map<int, vector<int>> positionsByNum2;
  int* cache;

  int helper(int i, int j) {
    if (i >= size1 || j >= size2) return 0;
    int cacheIndex = i * size2 + j;
    if (cache[cacheIndex] != -1) return cache[cacheIndex];
    int& num1 = (*nums1)[i];

    // 找到位置 i 下一個能匹配的 j
    int nextJ = -1;
    if (positionsByNum2.count(num1)) {
      nextJ = binarySearch(positionsByNum2[num1], j);
      // nextJ = linearSearch(positionsByNum2[num1], j);
    }

    int chosenResult = nextJ != -1 ? 1 + helper(i + 1, nextJ + 1) : 0;

    cache[cacheIndex] = max(chosenResult, helper(i + 1, j));

    return cache[cacheIndex];
  }
} solution;

int main() {
  // vector<int> nums1 = {1, 4, 2};
  // vector<int> nums2 = {1, 2, 4};

  // vector<int> nums1 = {1, 3, 7, 1, 7, 5};
  // vector<int> nums2 = {1, 9, 2, 5, 1};

  vector<int> nums1 = {2, 5, 1, 2, 5};
  vector<int> nums2 = {10, 5, 2, 1, 5, 2};

  cout << solution.maxUncrossedLines(nums1, nums2) << endl;

  // vector<int> position = {1, 3, 8, 10};
  // int j;

  // j = 0;
  // cout << solution.binarySearch(position, j) << endl;

  // j = 1;
  // cout << solution.binarySearch(position, j) << endl;

  // j = 2;
  // cout << solution.binarySearch(position, j) << endl;

  // j = 4;
  // cout << solution.binarySearch(position, j) << endl;

  // j = 10;
  // cout << solution.binarySearch(position, j) << endl;

  // j = 11;
  // cout << solution.binarySearch(position, j) << endl;

  return 0;
}