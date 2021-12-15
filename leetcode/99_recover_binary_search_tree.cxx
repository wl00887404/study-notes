#include <iostream>

#include "./TreeNode.cxx"
using namespace std;

/**
 * inorder 可以由小到大
 *
 * 1 2 3 4 5 6
 *
 * 1 5 3 4 2 6
 *
 * 一定會有一個凸起來一個凹下去
 * 一般來說一定是左小右大
 *
 * 5 則是左小右小
 * 2 是左大右大
 *
 * 6 2 3 4 5 1
 *
 */

/**
 * TODO: 
 *   Space O(1) 解有一個 Morris Inorder 沒看過
 *   花點時研究一下
 *   https://www.itread01.com/content/1545897069.html
 */

class Solution {
 public:
  void recoverTree(TreeNode* root) {
    inorder(root);
    int temp = right->val;
    right->val = left->val;
    left->val = temp;
  }

  TreeNode* last;
  TreeNode* left;
  TreeNode* right;
  void inorder(TreeNode*& node) {
    if (node == NULL) return;

    inorder(node->left);

    // 如果左側節點比自己大
    // 那就左側節點就是目標了
    if (left == NULL && last != NULL && last->val > node->val) {
      left = last;
    };

    if (left != NULL && last != NULL && last->val > node->val) {
      right = node;
    }

    last = node;
    inorder(node->right);
  }
};