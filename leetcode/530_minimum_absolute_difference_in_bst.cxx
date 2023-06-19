#include <iostream>
#include <climits>
#include "./TreeNode.cxx"

using namespace std;

/**
 * 要比較最小，就 inorder traverse
 */

class Solution {
 public:
  TreeNode* lastNode;
  int result;

  int getMinimumDifference(TreeNode* root) {
    lastNode = NULL;
    result = INT_MAX;

    helper(root);

    return result;
  }

  void helper(TreeNode* node) {
    if (node->left != NULL) helper(node->left);
    if (lastNode) result = min(result, node->val - lastNode->val);
    lastNode = node;

    if (node->right != NULL) helper(node->right);
  }
};