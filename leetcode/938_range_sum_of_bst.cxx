#include <iostream>

#include "TreeNode.cxx"
using namespace std;

class Solution {
 public:
  int rangeSumBST(TreeNode* root, int& low, int& high) {
    if (root == NULL) return 0;

    return (low <= root->val && root->val <= high ? root->val : 0) +
           rangeSumBST(root->left, low, high) +
           rangeSumBST(root->right, low, high);
  }
};