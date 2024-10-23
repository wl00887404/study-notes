#include <iostream>
#include <queue>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 *  加總完之後跑 quick select 就好
 */

class Solution {
 public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    vector<long long> levelSums;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      long long levelSum = 0;

      while (size--) {
        levelSum += q.front()->val;

        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right) q.push(q.front()->right);

        q.pop();
      }

      levelSums.push_back(levelSum);
    }

    int right = levelSums.size();
    if (k > right) return -1;

    sort(levelSums.begin(), levelSums.end());

    return levelSums[right - k];
  }

  // 從 215 複製過來的 quick select
  long long quickSelect(vector<long long>& array, int begin, int end, int k) {
    int pivot = end - 1;
    int i = begin;  // i 是比 pivot 大的元素的開始 index
    for (int j = i; j != pivot; j++) {
      if (array[j] < array[pivot]) {
        swap(array, i, j);
        i++;
      }
    }

    swap(array, pivot, i);

    if (end - i == k) return array[i];

    if (end - i > k) {
      return quickSelect(array, i + 1, end, k);
    }

    // 假設 k 是 5 ， end - i 是 3
    // 表示 pivot 是第 3 大的元素
    // 那就要在左側找第 2 大的元素
    k -= end - i;
    return quickSelect(array, begin, i, k);
  }

  void swap(vector<long long>& array, int& x, int& y) {
    int temp = array[y];
    array[y] = array[x];
    array[x] = temp;
  }
};