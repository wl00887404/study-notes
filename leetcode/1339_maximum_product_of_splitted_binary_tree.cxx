#include <iostream>
#include <stack>

#include "TreeNode.cxx"

using namespace std;

/**
 * 斷開的 edge 會形成一下子樹
 * ( 總和 - 子樹總和 ) * 子樹總和 = 產生的結果
 * 每個節點都跑過
 * 取最大即可
 */

class Solution {
 public:
  int maxProduct(TreeNode* root) {
    stack<TreeNode*> stack;
    int sum = accumulate(stack, root);
    stack.pop();
    unsigned long long result = 0;

    while (!stack.empty()) {
      unsigned long long val = stack.top()->val;
      result = max((sum - val) * val, result);
      stack.pop();
    }

    return result % 1000000007;
  }

  int accumulate(stack<TreeNode*>& stack, TreeNode* node) {
    if (node == NULL) return 0;

    int leftVal = accumulate(stack, node->left);
    int rightVal = accumulate(stack, node->right);

    node->val += leftVal + rightVal;
    stack.push(node);

    return node->val;
  }
};