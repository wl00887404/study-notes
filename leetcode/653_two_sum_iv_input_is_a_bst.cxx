
#include <iostream>
#include <queue>
#include <unordered_set>

#include "TreeNode.cxx"
using namespace std;

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> set;

    return helper(set, root, k);
  }

  bool helper(unordered_set<int>& set, TreeNode* node, int& k) {
    if (node == NULL) return false;
    if (set.count(k - node->val)) return true;

    set.insert(node->val);

    return helper(set, node->left, k) || helper(set, node->right, k);
  }
};