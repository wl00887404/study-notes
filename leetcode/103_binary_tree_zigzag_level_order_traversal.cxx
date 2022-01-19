#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 輸入 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
 * 要回傳 [[1], [3, 2], [4, 5, 6, 7], [15, 14, 13, 12, 11, 10, 9, 8]]
 *
 * 也就是偶數深度要反過來
 */

/**
 * 第一反應就是把偶數 reverse 呀
 * 輕鬆快樂簡單
 */

class ReverseSolution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) return {};

    vector<vector<int>> result;
    queue<TreeNode*> queue;

    queue.push(root);

    while (!queue.empty()) {
      int length = queue.size();
      result.push_back({});

      while (length--) {
        TreeNode*& node = queue.front();
        result.back().push_back(node->val);
        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
        queue.pop();
      }
    }

    bool isEven = 0;
    for (vector<int>& level : result) {
      if (isEven) {
        reverse(level.begin(), level.end());
      }

      isEven = !isEven;
    }

    return result;
  }
};

// 用 deque 再實作一次
class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) return {};

    vector<vector<int>> result;
    deque<TreeNode*> deque;

    deque.push_back(root);
    bool isEven = false;

    while (!deque.empty()) {
      result.push_back({});

      int length = deque.size();

      while (length--) {
        if (!isEven) {
          TreeNode*& node = deque.front();
          result.back().push_back(node->val);

          if (node->left) deque.push_back(node->left);
          if (node->right) deque.push_back(node->right);

          deque.pop_front();
        } else {
          TreeNode*& node = deque.back();
          result.back().push_back(node->val);

          if (node->right) deque.push_front(node->right);
          if (node->left) deque.push_front(node->left);

          deque.pop_back();
        }
      }

      isEven = !isEven;
    }

    return result;
  }
};