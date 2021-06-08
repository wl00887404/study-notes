#include <iostream>

#include "./TreeNode.cxx"

using namespace std;

/**
 * 除了窮舉到底有什麼辦法
 *
 * 一個點的可能性
 * 有上左右可以結合
 *
 * 自己
 * 上面的結果 + 自己 + 左邊的結果
 * 上面的結果 + 自己 + 右邊的結果
 * 左邊的結果 + 自己 + 右邊的結果
 */

/**
 * 答對（我也很驚訝）之後我發現
 * 葉子與獨子註解起來也沒問題
 * 回傳的結果 = 自己 or 自己 + 左右最大
 * 因為結果一定是自己的變化
 * 所以 return 0 是沒問題的
 */

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int result = root->val;

    helper(root, result);

    return result;
  }

  // 回傳可以接龍的結果
  // 並且把最大值更新在 result
  int helper(TreeNode* node, int& result) {
    if (node == NULL) return 0;
    // 葉子
    // if (node->left == NULL && node->right == NULL) {
    //   if (node->val > result) result = node->val;
    //   return node->val;
    // }

    // 獨子
    // if (node->left == NULL || node->right == NULL) {
    //   TreeNode* child = node->left != NULL ? node->left : node->right;
    //   int childResult = helper(child, result);
    //   int myResult = node->val + childResult;

    //   int finalResult = node->val > myResult ? node->val : myResult;
    //   if (finalResult > result) result = finalResult;

    //   return finalResult;
    // }

    // 雙子
    int leftResult = helper(node->left, result);
    int rightResult = helper(node->right, result);

    int adjacentResult = leftResult + node->val + rightResult;
    if (adjacentResult > result) result = adjacentResult;

    int myResult =
        node->val + (leftResult > rightResult ? leftResult : rightResult);

    int finalResult = node->val > myResult ? node->val : myResult;
    if (finalResult > result) result = finalResult;

    return finalResult;
  }
};

int main() { return 0; }