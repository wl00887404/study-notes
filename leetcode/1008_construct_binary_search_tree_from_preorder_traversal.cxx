#include <iostream>
#include <vector>

#include "TreeNode.cxx"

using namespace std;

class Solution {
 public:
  TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int>::iterator begin = preorder.begin();
    vector<int>::iterator end = preorder.end();

    TreeNode* dummyHead = new TreeNode(__INT_MAX__);
    helper(begin, end, dummyHead, dummyHead);

    return dummyHead->left;
  }

  void helper(vector<int>::iterator& begin, vector<int>::iterator& end,
              TreeNode* parent, TreeNode* max) {
    if (begin == end) return;

    TreeNode* node = new TreeNode(*begin);
    if (parent->val > node->val) {
      parent->left = node;
    } else {
      parent->right = node;
    }

    begin++;
    if (begin == end) return;

    // 下一位比較小往左
    if (*begin < node->val) {
      helper(begin, end, node, node);
    }

    if (begin == end) return;
    
    // 下一位比較大要找爸爸
    if (*begin > max->val) return;

    helper(begin, end, node, max);
  }
} solution;

int main() {
  vector<int> preorder = {1, 3};
  solution.bstFromPreorder(preorder);

  return 0;
}