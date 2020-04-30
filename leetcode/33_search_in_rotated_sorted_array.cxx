#include <iostream>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * 這題是 hard 吧 = =
 */

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (true) {
      switch (right - left) {
        case 0:
          return -1;
        case 1:
          return nums[left] == target ? left : -1;
        case 2: {
          if (nums[left] == target) return left;
          if (nums[left + 1] == target) return left + 1;

          return -1;
        }
      }

      int mid = left + (right - left) / 2;

      if (nums[mid] == target) return mid;

      if (nums[right - 1] < nums[mid]) {
        // left 到 mid 順序是正確的
        if (nums[left] == target) return left;
        if (nums[left] < target && target < nums[mid]) {
          return binarySearch(nums, target, left + 1, mid);
        }

        left = mid + 1;
      } else {
        // mid 到 right 順序是正確的
        if (nums[right - 1] == target) return right - 1;
        if (nums[mid] < target && target < nums[right - 1]) {
          return binarySearch(nums, target, mid + 1, right - 1);
        }

        right = mid;
      }
    }
  }

  int binarySearch(vector<int>& nums, int& target, int left, int right) {
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) return mid;

      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return -1;
  }
} solution;

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

  cout << solution.search(nums, 0) << endl;

  return 0;
}