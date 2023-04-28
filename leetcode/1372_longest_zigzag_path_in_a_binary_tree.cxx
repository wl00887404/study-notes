#include <iostream>

#include "./TreeNode.cxx"

using namespace std;

/**
 * 直接 DFS ZigZag
 * 順便把沒處理到的節點放進 queue.
 */

/**
 * 2023/4/19 祝自己生日快樂 🎂
 * 這題好難喔，寫不出來
 */

/**
 * 重新整理一下思維
 * 從 root 可以選擇往左走，與往右走
 * 往左走的話，要算 leftChild 往右走 ， leftChild -> rightChild 往左走
 * 往右走的話，要算 rightChild 往左走， rightChild -> leftChild 往右走
 * 再來要算 leftChild 往左走，與 rightChild 往右走
 */

class Solution {
 public:
  int longestZigZag(TreeNode* root) {
    result = 0;

    // 有 leftChild ，所以 path 為 1
    if (root->left) helper(root->left, true, 1);
    if (root->right) helper(root->right, false, 1);

    return result;
  }

  int result;

  void helper(TreeNode* node, bool isLeftChild, int path) {
    result = max(result, path);

    if (node->left) {
      // leftChild 往左走， nextPath 要重新算
      int nextPath = isLeftChild ? 1 : path + 1;
      helper(node->left, true, nextPath);
    }

    if (node->right) {
      int nextPath = !isLeftChild ? 1 : path + 1;
      helper(node->right, false, nextPath);
    }
  }
};