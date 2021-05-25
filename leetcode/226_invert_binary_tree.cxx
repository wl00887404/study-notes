#include "TreeNode.cxx"
using namespace std;

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;

    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
  }
};