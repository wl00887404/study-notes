#include <iostream>
#include <queue>

#include "./TreeNode.cxx"

using namespace std;

/**
 * preorder 通通丟進 queue 就解了
 *
 * Space O(n) 應該就只能硬插
 * node -> left 全部 -> right
 * right 要插在 left 的最右下
 *
 */

// 嘗試 Space O(1) 解
class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root) return;

    TreeNode* pointer = root;
    TreeNode* diveRight;

    while (pointer) {
      // 找到左側的最右下
      if (pointer->left) {
        diveRight = pointer->left;

        while (diveRight->right) {
          diveRight = diveRight->right;
        }
        diveRight->right = pointer->right;
        pointer->right = pointer->left;
        pointer->left = NULL;
      }

      pointer = pointer->right;
    }
  }
};

class QueueSolution {
 public:
  void flatten(TreeNode* root) {
    if (root == NULL) return;

    preorder(root);
    TreeNode* prev = queue.front();
    prev->left = NULL;
    queue.pop();

    while (!queue.empty()) {
      queue.front()->left = NULL;
      prev->right = queue.front();
      prev = queue.front();
      queue.pop();
    }
  }

  queue<TreeNode*> queue;

  void preorder(TreeNode* node) {
    if (node == NULL) return;

    queue.push(node);
    preorder(node->left);
    preorder(node->right);
  }
};

/**
 * 2022/7/27 又再寫一次
 */
class Solution {
 public:
  TreeNode* last;
  void flatten(TreeNode* root) {
    last = new TreeNode();
    helper(root);
  }

  void helper(TreeNode* node) {
    if (node == nullptr) return;

    last->right = node;
    last->left = nullptr;

    last = node;
    TreeNode* originalRight = node->right;

    helper(node->left);
    helper(originalRight);
  }
};