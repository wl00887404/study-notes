#include <iostream>
#include <queue>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  int minDepth(TreeNode* root) {
    queue<TreeNode*> q;
    if (root != NULL) q.push(root);
    int level = 0;
    while (!q.empty()) {
      level++;
      int size = q.size();
      while (size--) {
        const TreeNode* node = q.front();
        if (node->left == NULL && node->right == NULL) {
          return level;
        }
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        q.pop();
      }
    }

    return level;
  }
};