#include <iostream>
#include <stack>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> parents;
    TreeNode* p = root;

    do {
      parents.push(p);
      p = p->left;
    } while (p != NULL);

    while (true) {
      p = parents.top();

      if (k == 1) return p->val;
      
      k--;
      parents.pop();

      if (p->right != NULL) {
        p = p->right;
        do {
          parents.push(p);
          p = p->left;
        } while (p != NULL);
      }
    }
  }
};