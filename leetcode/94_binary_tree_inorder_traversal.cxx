#include <iostream>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;

    inorder(result, root);

    return result;
  }

  void inorder(vector<int>& result, TreeNode* node) {
    if (node == NULL) return;

    inorder(result, node->left);

    result.push_back(node->val);

    inorder(result, node->right);
  }
};