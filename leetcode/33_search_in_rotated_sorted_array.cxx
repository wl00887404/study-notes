#include <math.h>

#include <iostream>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * 這題是 hard 吧 = =
 */

/**
 * 當初寫是 2020/5/1
 * 2021/6/2 的我已經看不懂在幹麻了
 * 那個解答就當做紀念就好
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

/**
 * 超棒的點子：
 *   https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple
 *
 * nums = [4, 5, 6, 7, 0, 1, 2, 3], length = 8
 * I 為 Infinity 的縮寫
 *
 * 如果 target = 5
 * 那 nums = [4, 5, 6, 7, I, I, I, I] 可以用 binary search
 *
 * 如果 target = 1
 * 那 nums = [-I, -I, -I, -I, 0, 1, 2, 3] 可以用 binary search
 *
 *
 * 選用 nums[0] 判斷的情境為：
 *
 * [0, 1, 2, 3, 4, 5, 6, 7]
 *  m           0  t
 * m = Infinity
 *
 * [0, 1, 2, 3, 4, 5, 6, 7]
 *     t        0     m
 * m = -Infinity
 *
 * [0, 1, 2, 3, 4, 5, 6, 7]
 *              0  m     t
 * m = m
 */

class BestSolution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int mid = (left + right) / 2;

      double num = get(nums, target, mid);

      if (num == target) return mid;

      if (num > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }

 private:
  double get(vector<int>& nums, int& target, int& mid) {
    // 如果 mid 與 target 在同側（ nums[0] 的解釋看上面 ）
    if ((nums[mid] < nums[0]) == (target < nums[0])) return nums[mid];

    // 不在同側，使它變成同一側
    return target < nums[0] ? -INFINITY : INFINITY;
  }
};

class Solution153 {
 public:
  int search(vector<int>& nums, int target) {
    int rotatedLength = getRoatedLength(nums);
    int length = nums.size();
    int left = rotatedLength;
    int right = rotatedLength + length;

    while (left < right) {
      int mid = (left + right) / 2;
      int num = nums[mid % length];

      if (num == target) return mid % length;
      if (num > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }

 private:
  // 找到最小的位置
  int getRoatedLength(vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int mid = (left + right) / 2;

      if (mid > 0 && nums[mid - 1] > nums[mid]) return mid;
      if (nums[mid] > nums[right - 1]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  };
};

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

  cout << solution.search(nums, 0) << endl;

  return 0;
}