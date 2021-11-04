#include <iostream>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 * sum[i ... j] = sum[0, j] - sum[0, i]
 * subarray 找最大加總
 *
 * 53 也會用到這個觀念
 * 我印象中蠻多題的
 */

class Solution {
 public:
  int pathSum(TreeNode* root, int targetSum) {
    int result = 0;
    vector<int> sums = {0};

    helper(sums, targetSum, result, root);

    return result;
  }

  void helper(vector<int>& sums, int& targetSum, int& result, TreeNode* node) {
    if (node == NULL) return;

    int sum1 = sums.back() + node->val;
    for (int& sum2 : sums) {
      if (sum1 - sum2 == targetSum) result++;
    }

    sums.push_back(sum1);

    helper(sums, targetSum, result, node->left);
    helper(sums, targetSum, result, node->right);

    sums.pop_back();
  }
};