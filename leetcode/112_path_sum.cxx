#include <iostream>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 找葉子的基本題
 */

class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    return helper(root, targetSum);
  }

  bool helper(TreeNode* root, int& targetSum) {
    if (root == NULL) return false;

    if (root->left == NULL && root->right == NULL && root->val == targetSum) {
      return true;
    }

    targetSum -= root->val;

    if (helper(root->left, targetSum)) return true;
    if (helper(root->right, targetSum)) return true;

    targetSum += root->val;

    return false;
  }
};