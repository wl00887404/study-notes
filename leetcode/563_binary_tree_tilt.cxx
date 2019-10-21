#include <iostream>
using namespace std;

/*
 * 爆擊的成績大概是 24ms
 * 再優化大概就看 sum 會重複遞迴
 * 能否用 cache 的省去這個麻煩
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int findTilt(TreeNode *root) {
    if (root == nullptr) return 0;

    return findTilt(root->left) + findTilt(root->right) +
           abs(sum(root->left) - sum(root->right));
  }

  int abs(int x) { return x >= 0 ? x : x * -1; }

  int sum(TreeNode *root) {
    if (root == nullptr) return 0;

    return root->val + sum(root->left) + sum(root->right);
  }
};