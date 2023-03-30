#include <iostream>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  string tree2str(TreeNode* root) {
    if (root == NULL) return "";
    string result = to_string(root->val);

    if (root->left == NULL && root->right == NULL) return result;
    result += "(" + tree2str(root->left) + ")";
    if (root->right != NULL) result += "(" + tree2str(root->right) + ")";

    return result;
  }
};