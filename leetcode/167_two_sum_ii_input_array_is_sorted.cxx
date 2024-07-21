#include <iostream>
#include <vector>

using namespace std;

/**
 * 看別人的答案，原來左右夾起來就行了
 */

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int size = numbers.size();
    int i;
    int j = -1;

    for (i = 0; i < size; i++) {
      j = binarySearch(numbers, target - numbers[i], i + 1, size);

      if (j != -1) break;
    }

    return {i + 1, j + 1};
  }

  int binarySearch(vector<int>& numbers, int target, int left, int right) {
    while (left < right) {
      int mid = (left + right) / 2;

      if (numbers[mid] == target) return mid;

      if (numbers[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }
};