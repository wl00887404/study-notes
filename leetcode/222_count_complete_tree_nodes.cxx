#include <math.h>

#include <iostream>
#include <stack>
#include <vector>

#include "TreeNode.cxx"

using namespace std;

/**
 * 往左到最深確認最少的深度 d
 * 表示至少有 2 ^ d 個節點
 * 這一層可能有 2 ^ d 個節點（包含找到最左側的）
 * 二分搜尋最後一層的節點數
 */

/**
 * TODO: 研究最佳解
 */

class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (root == NULL) return 0;

    // 往左下挖找深度
    int depth = 0;
    TreeNode* pointer = root;
    while (pointer->left) {
      depth++;
      pointer = pointer->left;
    }

    int left = pow(2, depth);
    int right = pow(2, depth + 1);

    while (left < right) {
      int mid = (left + right) / 2;

      if (getNth(root, mid) != NULL) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left - 1;
  }

  TreeNode* getNth(TreeNode* root, int n) {
    stack<bool> stack;
    while (n != 1) {
      stack.push(n % 2);
      n /= 2;
    }
    TreeNode* pointer = root;
    while (!stack.empty()) {
      pointer = stack.top() == 0 ? pointer->left : pointer->right;
      stack.pop();
    }

    return pointer;
  }
};