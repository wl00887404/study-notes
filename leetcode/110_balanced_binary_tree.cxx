#include <iostream>
#include <queue>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  bool isBalanced(TreeNode* root) { return checkBalanced(root) != -1; }

  int checkBalanced(TreeNode* root) {
    if (root == NULL) return 0;

    int leftHeight = checkBalanced(root->left);
    int rightHeight = checkBalanced(root->right);

    if (leftHeight == -1 || rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
  }
};