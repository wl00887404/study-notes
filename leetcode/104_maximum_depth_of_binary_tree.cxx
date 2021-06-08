#include <iostream>
#include <queue>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    queue<TreeNode*> queue;
    int depth = 0;
    if (root != NULL) queue.push(root);

    while (!queue.empty()) {
      depth++;
      int length = queue.size();
      while (length--) {
        TreeNode* node = queue.front();
        if (node->left != NULL) queue.push(node->left);
        if (node->right != NULL) queue.push(node->right);
        queue.pop();
      }
    }

    return depth;
  }
};
