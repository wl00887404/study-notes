#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 阿不就 quick select
 */

/**
 * 幹我自己寫得 quick select 怎麼更慢
 * 內省式排序真的這麼屌嗎？
 */

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    numsPointer = &nums;
    int begin = 0;
    int end = nums.size();

    return helper(begin, end, k);
  }

  vector<int>* numsPointer;

  int helper(int& begin, int& end, int& k) {
    vector<int>& nums = *numsPointer;
    int pivot = end - 1;
    int i = begin;  // i 是比 pivot 大的元素的開始 index
    for (int j = i; j != pivot; j++) {
      if (nums[j] < nums[pivot]) {
        swap(i, j);
        i++;
      }
    }

    swap(pivot, i);

    if (end - i == k) return nums[i];

    if (end - i > k) {
      i++;
      return helper(i, end, k);
    }

    // 假設 k 是 5 ， end - i 是 3
    // 表示 pivot 是第 3 大的元素
    // 那就要在左側找第 2 大的元素
    k -= end - i;
    return helper(begin, i, k);
  }

  void swap(int& x, int& y) {
    vector<int>& nums = *numsPointer;
    int temp = nums[y];
    nums[y] = nums[x];
    nums[x] = temp;
  }
};

class SortSolution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    return nums[nums.size() - k];
  }
};