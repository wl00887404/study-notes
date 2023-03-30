#include <iostream>
#include <queue>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
      return new TreeNode(val, root, NULL);
    }

    queue<TreeNode*> q;
    q.push(root);

    while (depth != 2) {
      int size = q.size();
      while (size--) {
        TreeNode*& current = q.front();
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
        q.pop();
      }

      depth--;
    }

    while (!q.empty()) {
      TreeNode*& current = q.front();
      TreeNode* nextLeft = new TreeNode(val);
      nextLeft->left = current->left;
      current->left = nextLeft;

      TreeNode* nextRight = new TreeNode(val);
      nextRight->right = current->right;
      current->right = nextRight;

      q.pop();
    }

    return root;
  }
};