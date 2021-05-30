#include <iostream>
#include <queue>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 * DFS 基本題
 */

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    queue<TreeNode*> queue;
    if (root != NULL) queue.push(root);

    int size;
    while (size = queue.size()) {
      vector<int> values;
      while (size--) {
        TreeNode* node = queue.front();
        values.push_back(node->val);
        if (node->left != NULL) queue.push(node->left);
        if (node->right != NULL) queue.push(node->right);
        queue.pop();
      }
      result.push_back(values);
    }

    return result;
  }
};