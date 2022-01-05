#include <iostream>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  bool isSymmetric(TreeNode* root) { return helper(root->left, root->right); }

  bool helper(TreeNode*& left, TreeNode*& right) {
    if (left == NULL && right == NULL) return true;
    if (left == NULL || right == NULL) return false;
    if (left->val != right->val) return false;

    return helper(left->left, right->right) && helper(left->right, right->left);
  }
};
