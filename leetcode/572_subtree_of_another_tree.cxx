struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isSubtree(TreeNode *s, TreeNode *t) {
    if (isSameTree(s, t)) return true;
    if (s->left != nullptr && isSubtree(s->left, t)) return true;
    if (s->right != nullptr && isSubtree(s->right, t)) return true;

    return false;
  }

  bool isSameTree(TreeNode *s, TreeNode *t) {
    if (s == nullptr && t == nullptr) return true;
    if (s == nullptr || t == nullptr) return false;

    if (s->val != t->val) return false;
    if (!isSameTree(s->left, t->left)) return false;
    if (!isSameTree(s->right, t->right)) return false;

    return true;
  }
};