#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 2023/9/18
 * FIXME: 未完成
 */

/**
 * 2022/1/17
 * 如果保證有答案
 * [1, 2, 3, 4, 5, 6]
 *
 * 公式配法就是 [1, 6, 2, 5, 3, 4]
 * 最小 最大 第二小 第二大 ...
 */

/**
 * 2022/1/20
 * https://leetcode.com/problems/wiggle-sort-ii/discuss/77677/O(n)%2BO(1)-after-median-Virtual-Indexing
 * 上次寫到剛好遇到平均數不知道怎麼處理
 * 看一下討論區（是 StefanPochmann 耶）恍然大悟應該要用中位數才對
 * c++ 有 nth_children 可以用
 * 直接實作應該就寫 QuickSelect 就好
 */

/**
 *  0  1  2  3  4  5
 * [1, 2, 3, 4, 5, 6], size = 6
 * size / 2 = 3
 *
 * 1 6 2 5 3 4
 *
 *  0  1  2  3  4  5
 * [1, 2, 3, 4, 5], size = 5
 * size / 2 = 2
 *
 * 1 5 2 4 3
 *
 * 只要大於等於中位數都會在 2n + 1 的位置
 */

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    int size = nums.size();
    nth_element(nums.begin(), nums.begin() + size / 2, nums.end());
    // nth_element 操作完
    int medium = nums[size / 2];

    int shouldBeLower = -1;
    int shouldBeGreater = -1;

    for (int i = 0; i < size; i++) {
    }
  }
};