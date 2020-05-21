#include <iostream>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;


class Solution {
 public:
  bool isCousins(TreeNode *root, int x, int y) {
    if (x == y) return false;

    vector<TreeNode *> parents = {root};
    vector<TreeNode *> founds;

    int i = 0;
    int length = 1;

    while (i < length && founds.size() == 0) {
      for (; i < length && founds.size() != 2; i++) {
        if (parents[i]->left != NULL) {
          if (parents[i]->left->val == x || parents[i]->left->val == y) {
            founds.push_back(parents[i]);
          } else {
            parents.push_back(parents[i]->left);
          }
        }
        if (parents[i]->right != NULL) {
          if (parents[i]->right->val == x || parents[i]->right->val == y) {
            founds.push_back(parents[i]);
          } else {
            parents.push_back(parents[i]->right);
          }
        }
      }

      length = parents.size();
    }

    return founds.size() == 2 && founds[0] != founds[1];
  }
} solution;

int main() {
  TreeNode *root =
      new TreeNode(1, new TreeNode(2, NULL, new TreeNode(4)), new TreeNode(3));

  cout << solution.isCousins(root, 2, 3) << endl;

  return 0;
}