#include <iostream>
#include <queue>
#include <unordered_map>

#include "./TreeNode.cxx"
using namespace std;

/**
 * 麻煩的點就是不知道 p q 在哪
 * 只能 BFS 去找
 */

/**
 * DFS 的程式碼有夠簡潔的
 * TODO: 忘記了再回來看吧
 */

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL or root == p or root == q) return root;

    auto left = lowestCommonAncestor(root->left, p, q);
    auto right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL && right == NULL) return NULL;
    if (left != NULL && right != NULL) return root;
    return left == NULL ? right : left;
  }
};

class MySolution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 其中一人沒爸爸
    // 根本不需要找
    if (root == p || root == q) return root;

    // node, parent
    unordered_map<TreeNode*, TreeNode*> map;
    queue<TreeNode*> queue;
    queue.push(root);
    int foundCount = 0;
    int pLevel;
    int qLevel;
    int level = 0;

    while (true) {
      int size = queue.size();
      level++;

      while (size--) {
        TreeNode*& node = queue.front();
        if (node->left != NULL) {
          map[node->left] = node;
          queue.push(node->left);
        }

        if (node->right != NULL) {
          map[node->right] = node;
          queue.push(node->right);
        }

        if (node->left == p || node->right == p) {
          foundCount++;
          pLevel = level;
          if (foundCount == 2) break;
        }

        if (node->left == q || node->right == q) {
          foundCount++;
          qLevel = level;
          if (foundCount == 2) break;
        }

        queue.pop();
      }
      if (foundCount == 2) break;
    }

    // 找到 p q 的 ancestors 與 level 了
    return findCommonAncestor(map, q, qLevel, p, pLevel);
  }

  TreeNode* findCommonAncestor(unordered_map<TreeNode*, TreeNode*>& map,
                               TreeNode*& p, int& pLevel, TreeNode*& q,
                               int& qLevel) {
    if (qLevel > pLevel) return findCommonAncestor(map, q, qLevel, p, pLevel);

    while (pLevel > qLevel) {
      p = map[p];
      pLevel--;
    }

    while (p != q) {
      p = map[p];
      q = map[q];
    }

    return p;
  }
};