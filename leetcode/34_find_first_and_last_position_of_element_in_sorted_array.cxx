#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * binary search 有可能 overflow :
 * https://stackoverflow.com/questions/25571359/why-we-write-lohi-lo-2-in-binary-search
 *
 * 2 * log(n) 也是一種 log(n)
 */

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int length = nums.size();

    if (length == 0) return {-1, -1};

    int index = binarySearch(nums, target, 0, length);

    if (index == -1) return {-1, -1};

    int left = index;
    int right = index;

    while (left != 0) {
      int nextLeft = binarySearch(nums, target, 0, left);

      if (nextLeft == -1) break;

      left = nextLeft;
    };

    while (right != length - 1) {
      int nextRight = binarySearch(nums, target, right + 1, length);

      if (nextRight == -1) break;

      right = nextRight;
    };

    return {left, right};
  }

  int binarySearch(vector<int>& nums, int target, int left, int right) {
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
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  vector<int> results = solution.searchRange(nums, 8);

  log(results);

  return 0;
}