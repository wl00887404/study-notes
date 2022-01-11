#include <iostream>
#include <vector>

using namespace std;

/**
 * 與 852 相同
 * nums[-1] 與 nums[size] 都是無限小
 *
 * 結果 O(n) 跑出來還比較快
 * 難怪這題這麼多倒讚
 */

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    numsPointer = &nums;
    size = nums.size();

    return helper(0, size);
  }

  vector<int>* numsPointer;
  int size;

  int helper(int begin, int end) {
    if (begin == end) return -1;
    vector<int>& nums = *numsPointer;
    int mid = (begin + end) / 2;

    if ((0 == mid || nums[mid - 1] < nums[mid]) &&
        (mid + 1 == size || nums[mid] > nums[mid + 1])) {
      return mid;
    }

    int fromLeft = helper(begin, mid);
    if (fromLeft != -1) return fromLeft;

    return helper(mid + 1, end);
  }
};