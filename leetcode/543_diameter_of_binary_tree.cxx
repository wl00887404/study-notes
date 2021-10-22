#include <iostream>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int result = 0;

    dfs(root, result);

    return result;
  }

  void dfs(TreeNode* node, int& result) {
    if (node->left == NULL && node->right == NULL) {
      node->val = 0;
      return;
    }

    if (node->left) dfs(node->left, result);    // 算左側的 children
    if (node->right) dfs(node->right, result);  // 算右側的 children

    int leftValue = node->left ? node->left->val + 1 : 0;
    int rightValue = node->right ? node->right->val + 1 : 0;

    // root->val 存最長的的後裔長度
    node->val = max(leftValue, rightValue);

    // 每個節點的結果 = 左側 + 右側
    int value = leftValue + rightValue;

    result = max(result, value);
  }
};