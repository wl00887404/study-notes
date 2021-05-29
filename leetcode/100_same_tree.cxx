#include <iostream>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;

    if (!isSameTree(p->left, q->left)) return false;
    if (!isSameTree(p->right, q->right)) return false;

    return true;
  }
};