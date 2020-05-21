#include <iostream>
#include <limits>
#include <vector>

#include "./TreeNode.cxx"
#include "./log.cxx"
using namespace std;

class Solution {
 public:
  bool isValidBST(TreeNode *root) {
    if (root == NULL) return true;

    if (!isChildValid(root->left, NULL, &root->val)) return false;

    return isChildValid(root->right, &root->val, NULL);
  }

  bool isChildValid(TreeNode *node, int *min, int *max) {
    if (node == NULL) return true;

    if (min != NULL && *min >= node->val) return false;
    if (max != NULL && node->val >= *max) return false;

    if (!isChildValid(node->left, min, &node->val)) return false;

    return isChildValid(node->right, &node->val, max);
  }
} solution;

class T1Solution {
 public:
  int *last = NULL;
  bool isValidBST(TreeNode *root) {
    if (root == NULL) return true;

    if (!isValidBST(root->left)) return false;
    if (last && *last >= root->val) return false;
    last = &root->val;
    if (!isValidBST(root->right)) return false;
    return true;
  };
};

int main() {
  TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

  cout << solution.isValidBST(root) << endl;

  return 0;
}

/**
 *  3
 *  1                5
 *  0         2      4 6
 *  null null null 3
 */