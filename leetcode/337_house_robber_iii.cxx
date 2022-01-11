#include <iostream>
#include <unordered_map>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 與 198 同樣的概念
 * 只是變成了 Binary Tree
 */

/**
 * 看每個人的寫法都是這樣
 * 另外有想到可以直接修改 TreeNode 的值
 * 這樣就不需要另外使用 unordered_map
 *
 * 同樣的概念可以應用在 198
 */

class Solution {
 public:
  unordered_map<TreeNode*, int> cache;

  int rob(TreeNode* root) {
    if (root == NULL) return 0;
    if (cache.count(root)) return cache[root];

    int notSelectedResult = rob(root->left) + rob(root->right);

    int selectedResult = root->val;

    if (root->left) {
      selectedResult += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right) {
      selectedResult += rob(root->right->left) + rob(root->right->right);
    }

    cache[root] = max(notSelectedResult, selectedResult);

    return cache[root];
  }
};