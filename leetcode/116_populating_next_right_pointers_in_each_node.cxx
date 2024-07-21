#include <iostream>
#include <queue>

using namespace std;

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class QueueSolution {
 public:
  Node* connect(Node* root) {
    queue<Node*> queue;
    if (root) queue.push(root);

    while (!queue.empty()) {
      Node* lastNode = NULL;
      int i = queue.size();

      while (i--) {
        Node*& node = queue.front();

        if (lastNode) {
          lastNode->next = node;
        }

        if (node->left) queue.push(node->left);
        if (node->right) queue.push(node->right);
        lastNode = node;
        queue.pop();
      }
    }

    return root;
  }
};

/**
 * 想不到 Space Complexity O(n) 的解
 * 直接看範例答案
 *
 * 靠北
 * 右側的 next = 自己 next 的左側啦幹
 */

/**
 * 2024/3/10 update
 * 因為他是 perfect binary tree ，所以不會有跳過節點的問題
 * 117 就不是 perfect binary tree 了
 */

class ForumSolution {
 public:
  Node* connect(Node* root) {
    if (!root) return NULL;
    if (root->left) {
      root->left->next = root->right;
      if (root->next) {
        root->right->next = root->next->left;  // 跨 parent 連結
      }
    }
    connect(root->left);
    connect(root->right);
    return root;

    // there is no condition because by default next value is NULL
  }
};