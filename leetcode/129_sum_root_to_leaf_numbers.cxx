#include <iostream>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    if (root == NULL) return 0;

    int result = 0;
    int sum = 0;

    helper(result, sum, root);

    return result;
  }

  void helper(int& result, int& sum, TreeNode* node) {
    if (node->left == NULL && node->right == NULL) {
      result += sum + node->val;
      return;
    }

    sum = (sum + node->val) * 10;
    if (node->left) helper(result, sum, node->left);
    if (node->right) helper(result, sum, node->right);

    sum = sum / 10 - node->val;
  }
} solution;