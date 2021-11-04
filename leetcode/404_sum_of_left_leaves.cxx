#include <queue>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL) return 0;

    int result = 0;
    queue<TreeNode*> nodeQueue;
    queue<bool> isLeftQueue;
    nodeQueue.push(root);
    isLeftQueue.push(false);

    while (!nodeQueue.empty()) {
      TreeNode*& node = nodeQueue.front();
      bool& isLeft = isLeftQueue.front();

      if (isLeft && node->left == NULL && node->right == NULL) {
        result += node->val;
      }

      if (node->left != NULL) {
        nodeQueue.push(node->left);
        isLeftQueue.push(true);
      }
      if (node->right != NULL) {
        nodeQueue.push(node->right);
        isLeftQueue.push(false);
      }

      nodeQueue.pop();
      isLeftQueue.pop();
    }

    return result;
  }
};