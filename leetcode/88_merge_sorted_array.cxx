#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * 2021/12/9 寫完
 * 2021/12/10 重看題目
 *
 * 靠北 nums1 原來本來就是有 m + n 的長度喔
 */

/**
 * TODO: 要怎麼只執行 O(m + n) 此呀
 * 插入的話一定是 O(m)
 * 要靠 swap 的嗎？
 */

/**
 * swap 情境 1
 * 1 2 3 0 0 0
 * 2 5 6
 *
 * 1 < 2  | 維持不動 i++
 * 2 == 2 | 維持 i++
 * 3 > 2  | 2 應該要插入在 3 前面， 2 與 3 交換
 *
 * 1 2 2 0 0 0
 * 3 5 6
 */

/**
 * 5 0 0
 * 3 4
 *
 * 5 > 3 | 3 應該要在 5 前面， 5 與 3 交換
 *
 * 3 0 0
 * 5 4
 *
 * [4,5,6,0,0,0]
 * [1,2,3]
 *
 * 1 2 3 5 6 0 0
 * 4
 */

/**
 * 受不了直接看解答
 * https://leetcode.com/problems/merge-sorted-array/discuss/29522/This-is-my-AC-code-may-help-you
 *
 * 靠北
 * 從後面回來
 * 就可以直接排序了
 *
 * TODO: 忘記之後再回來寫一下這題吧
 */

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;

    while (i >= 0 && j >= 0) {
      if (nums1[i] < nums2[j]) {
        nums1[k--] = nums2[j--];
      } else {
        nums1[k--] = nums1[i--];
      }
    }
    while (j >= 0) {
      nums1[k--] = nums2[j--];
    }
  }
};

class QueueSolution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    queue<int> queue;

    int i = 0;
    int j = 0;

    while (i < m && j < n) {
      if (nums1[i] < nums2[j]) {
        queue.push(nums1[i]);
        i++;
      } else {
        queue.push(nums2[j]);
        j++;
      }
    }

    while (i < m) {
      queue.push(nums1[i]);
      i++;
    }

    while (j < n) {
      queue.push(nums2[j]);
      j++;
    }

    for (i = 0; i < m + n; i++) {
      nums1[i] = queue.front();
      queue.pop();
    }
  }
};

int main() {
  vector<int> nums1 = {2, 0};
  vector<int> nums2 = {1};
  int m = 1;
  int n = 1;

  // solution.merge(nums1, m, nums2, n);

  return 0;
}
