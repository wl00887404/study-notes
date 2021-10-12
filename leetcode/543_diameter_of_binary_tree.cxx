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

  void dfs(TreeNode* root, int& result) {
    if (root->left == NULL && root->right == NULL) {
      root->val = 0;
      return;
    }

    if (root->left) dfs(root->left, result);    // 算左側的 children
    if (root->right) dfs(root->right, result);  // 算右側的 children

    int leftValue = root->left ? root->left->val + 1 : 0;
    int rightValue = root->right ? root->right->val + 1 : 0;

    // root->val 存最長的的後裔長度
    root->val = max(leftValue, rightValue);

    // 每個節點的結果 = 左側 + 1 + 右側 + 1
    int value = 0;
    if (root->left) value += root->left->val + 1;
    if (root->right) value += root->right->val + 1;

    result = max(result, value);
  }
};