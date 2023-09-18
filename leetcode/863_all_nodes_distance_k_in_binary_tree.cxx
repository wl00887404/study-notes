#include <iostream>
#include <queue>
#include <vector>

#include "./TreeNode.cxx"

using namespace std;

class Solution {
 public:
  vector<int> result;
  TreeNode* target;

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    result.clear();
    this->target = target;

    helper(root, k);

    return result;
  }

  int helper(TreeNode* node, int k) {
    if (node->val == target->val) {
      pushKLevelNodes(node, k);
      return k - 1;  // 讓父節點知道還剩下多少距離
    }

    int leftK = node->left != NULL ? helper(node->left, k) : -1;

    // k 為正就表示，在左側找到了目標節點了
    // leftK 是目標節點返回到此節點，還剩下的 k
    if (leftK >= 0) {
      node->left = NULL; // 因為是返回了父節點，所以側不需要處理
      pushKLevelNodes(node, leftK);

      return leftK - 1;
    }

    int rightK = node->right != NULL ? helper(node->right, k) : -1;

    // k 為正就表示，在右側找到了目標節點了
    // rightK 是目標節點返回到此節點，還剩下的 k
    if (rightK >= 0) {
      node->right = NULL; // 因為是返回了父節點，所以側不需要處理
      pushKLevelNodes(node, rightK);

      return rightK - 1;
    }

    return -1;
  }

  void pushKLevelNodes(TreeNode* root, int k) {
    queue<TreeNode*> q;
    q.push(root);

    while (k != 0) {
      int size = q.size();

      while (size--) {
        TreeNode* n = q.front();
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
        q.pop();
      }

      k--;
    }

    while (!q.empty()) {
      result.push_back(q.front()->val);
      q.pop();
    }
  }
};