#include <iostream>
#include <queue>

using namespace std;

class Node {
 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

/**
 *
 * 如果遇到 child 要 dive
 * child 成為 next
 */

class Solution {
 public:
  Node* flatten(Node* head) {
    flattenAndReturnLast(head);

    return head;
  }

  Node* flattenAndReturnLast(Node* node) {
    if (node == NULL || (node->next == NULL && node->child == NULL)) {
      return node;
    }

    Node* prevNode = NULL;
    while (node != NULL) {
      // 遇到有 child 的情境
      if (node->child != NULL) {
        Node* originalNext = node->next;
        Node* childLast = flattenAndReturnLast(node->child);
        node->next = node->child;
        node->child->prev = node;
        node->child = NULL;
        childLast->next = originalNext;
        if (originalNext != NULL) originalNext->prev = childLast;
      }

      prevNode = node;
      node = node->next;
    }

    return prevNode;
  }
};

class QueueSolution {
 public:
  Node* flatten(Node* head) {
    if (head == NULL) return head;

    queue<Node*> queue;
    helper(queue, head);
    Node* pointer = head;
    queue.pop();

    while (!queue.empty()) {
      pointer->next = queue.front();
      queue.front()->prev = pointer;
      pointer->child = NULL;

      pointer = pointer->next;
      queue.pop();
    }

    return head;
  }
  void helper(queue<Node*>& queue, Node* node) {
    if (node == NULL) return;

    queue.push(node);

    if (node->child) helper(queue, node->child);

    helper(queue, node->next);
  }
};