#include <iostream>
#include <queue>
#include <vector>

#include "./TreeNode.cxx"

using namespace std;

/**
 * 題意要每一層最右邊的節點
 * 直接 BFS 一個 queue 找每層最右側的節點就解了
 */

class QueueSolution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
      int size = queue.size();

      while (size--) {
        TreeNode*& node = queue.front();

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);

        if (size == 0) result.push_back(node->val);

        queue.pop();
      }
    }

    return result;
  }
};