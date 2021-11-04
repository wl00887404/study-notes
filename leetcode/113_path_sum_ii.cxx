#include <iostream>
#include <queue>
#include <stack>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 找出所有符合的節點
 * 然後處理 parents 們
 * 寫得好像有點醜
 */

class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    if (root == NULL) return {};

    vector<vector<int>> result;
    vector<int> path;

    helper(root, result, path, targetSum);

    return result;
  }

  void helper(TreeNode* root, vector<vector<int>>& result, vector<int>& path,
              int& targetSum) {
    path.push_back(root->val);

    if (root->left == NULL && root->right == NULL && root->val == targetSum) {
      result.push_back(path);
    }

    targetSum -= root->val;

    if (root->left) {
      helper(root->left, result, path, targetSum);
    }
    if (root->right) {
      helper(root->right, result, path, targetSum);
    }

    path.pop_back();
    targetSum += root->val;
  }
};