
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 105 106 相關題耶
 */

/**
 * 被 106 整慘了 :sob:
 * 105 比較直觀比較好想出來
 */

/**
 * 依據 105 + 106 的洗禮
 * preorder 是左側開始
 * postorder 是倒過來右側開始
 *
 * preorder 為 node left
 * 如果沒有 left 的話
 * 則為 parnet 的 right 或是 grandparnet 的 right
 *
 * postorder 為 right node
 * 如果沒有 right 的話
 * 則為 parnet 的 left 或是 grandparnet 的 left
 *
 * BFS 才符合需求
 * 確認好 parent 的 left right 關系
 * 後面就可以準確的確定是否有 children
 */

class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& preorder,
                                 vector<int>& postorder) {
    int size = preorder.size();
    unordered_set<int> isUsed;
    // node, possible left
    unordered_map<int, int> maybeLefts;
    // node, possible right
    unordered_map<int, int> maybeRights;

    for (int i = 1; i < size; i++) {
      maybeLefts[preorder[i - 1]] = preorder[i];
    }
    maybeLefts[preorder[size - 1]] = 0;

    for (int i = 1; i < size; i++) {
      maybeRights[postorder[i]] = postorder[i - 1];
    }
    maybeRights[postorder[0]] = 0;

    TreeNode* head = new TreeNode(preorder[0]);
    queue<TreeNode*> queue;
    queue.push(head);

    while (!queue.empty()) {
      TreeNode*& node = queue.front();

      int& maybeLeft = maybeLefts[node->val];
      int& maybeRight = maybeRights[node->val];

      if (maybeLeft != 0 && !isUsed.count(maybeLeft)) {
        node->left = new TreeNode(maybeLeft);
        queue.push(node->left);
        isUsed.insert(maybeLeft);
      }

      if (maybeRight != 0 && !isUsed.count(maybeRight)) {
        node->right = new TreeNode(maybeRight);
        queue.push(node->right);
        isUsed.insert(maybeRight);
      }

      queue.pop();
    }

    return head;
  }
};