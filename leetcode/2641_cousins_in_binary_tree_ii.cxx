#include <iostream>
#include <queue>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    unordered_map<TreeNode*, int> siblingValueMap;

    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(root);

    while (!q1.empty()) {
      int size = q1.size();
      int sum = 0;

      while (size--) {
        TreeNode*& node = q1.front();
        sum += node->val;

        if (node->left) {
          q1.push(node->left);
          siblingValueMap[node->left] = node->right ? node->right->val : 0;
        }

        if (node->right) {
          q1.push(node->right);
          siblingValueMap[node->right] = node->left ? node->left->val : 0;
        }

        q2.push(node);
        q1.pop();
      }

      while (!q2.empty()) {
        TreeNode*& node = q2.front();
        node->val = sum - node->val - siblingValueMap[node];
        q2.pop();
      }
    }

    return root;
  }
};