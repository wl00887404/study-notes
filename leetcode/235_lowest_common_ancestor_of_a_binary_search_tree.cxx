#include <iostream>
#include <stack>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> pStack;
    stack<TreeNode*> qStack;

    find(root, p->val, pStack);
    find(root, q->val, qStack);

    do {
      if (pStack.size() == qStack.size()) {
        pStack.pop();
        qStack.pop();
      } else if (pStack.size() > qStack.size()) {
        pStack.pop();
      } else {
        qStack.pop();
      }
    } while (pStack.top() != qStack.top());

    return pStack.top();
  }

  void find(TreeNode* node, int& val, stack<TreeNode*>& stack) {
    stack.push(node);
    if (node->val == val) return;

    TreeNode* nextNode = node->val > val ? node->left : node->right;
    find(nextNode, val, stack);
  };
};