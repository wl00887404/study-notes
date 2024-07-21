#include <iostream>
#include <queue>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  bool isEvenOddTree(TreeNode *root) {
    int slope = 1;
    int remainder = 1;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();
      TreeNode dummyNode = TreeNode(q.front()->val - slope);
      TreeNode *node = &dummyNode;

      while (size--) {
        if ((q.front()->val - node->val) * slope <= 0) {
          return false;
        }
        node = q.front();
        if (node->val % 2 != remainder) return false;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        q.pop();
      }

      slope *= -1;
      remainder = (remainder + 1) % 2;
    }

    return true;
  }
};