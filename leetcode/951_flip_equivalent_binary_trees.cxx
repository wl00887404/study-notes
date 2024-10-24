#include <iostream>

#include "./TreeNode.cxx"
using namespace std;

class Solution {
 public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    if (root1->val != root2->val) return false;

    // 有可能 flip，不知道 child 怎麼對應
    
    if (flipEquiv(root1->left, root2->left) &&
        flipEquiv(root1->right, root2->right)) {
      return true;
    }

    return flipEquiv(root1->left, root2->right) &&
           flipEquiv(root1->right, root2->left);
  }
};