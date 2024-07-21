#include <iostream>
#include <string>

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

/**
 * 如果是一層一層做就很容易
 * 用 preorder 就一定沒辦法一層一層做
 *
 * left node 的 next 有可能是
 *   1. parent->right
 *   2. parent->next->left
 *   3. parent->next->right
 *   4. parent->next->next->left
 *   5. parent->next->next->right
 *
 * right node 的 next 有可能是
 *   1. parent->next->left
 *   2. parent->next->right
 *   3. parent->next->next->left
 *   4. parent->next->next->right
 */

/**
 * 有 left 也有 right
 *   => left->next = right ， right 往 parent-> next 找
 * 有 left 沒有 right
 *   => left 往 parent->next 找
 * 沒有 left 有 right
 *   => right 往 parent->next 找
 *
 * 都處理完之後，要先處理 ->next ，再處理 ->left ->right
 */
class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return NULL;
    if (root->left == NULL && root->right == NULL) return root;

    Node* next = getNext(root);

    if (root->left != NULL & root->right != NULL) {
      // 兩邊都有，直接連起來，幫 right 找 next
      root->left->next = root->right;
      root->right->next = next;
    } else if (root->left != NULL) {
      // 只有 left，幫 left 找 next
      root->left->next = next;
    } else {
      // 只有 next，幫 next 找 next
      root->right->next = next;
    }

    /**
     * 先往右再往左
     * 因為左側會用 parent->next->next ... 去找 next->child
     * 所以右側的 next 關係要先建立好
     */
    connect(root->right);
    connect(root->left);

    return root;
  }

  Node* getNext(Node* node) {
    Node* current = node->next;

    while (current != NULL) {
      if (current->left != NULL) return current->left;
      if (current->right != NULL) return current->right;
      current = current->next;
    }

    return NULL;
  }
};