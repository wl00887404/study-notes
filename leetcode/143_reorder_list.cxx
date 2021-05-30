#include <iostream>
#include <queue>
#include <stack>

#include "./ListNode.cxx"
using namespace std;

/**
 *  0 => 1 => 2 => 3 => 4
 *  0 => 4 => 1 => 3 => 2
 *
 *  0 => 1 => 2 => 3
 *  0 => 3 => 1 => 2
 */

class Solution {
 public:
  void reorderList(ListNode* head) {
    queue<ListNode*> queue;
    stack<ListNode*> stack;
    ListNode* pointer = head;

    while (pointer != NULL) {
      stack.push(pointer);
      queue.push(pointer);
      pointer = pointer->next;
    }

    int length = queue.size();
    ListNode dummyHead = ListNode();
    pointer = &dummyHead;
    int i = length / 2;
    while (i--) {
      pointer->next = queue.front();
      pointer->next->next = stack.top();
      pointer = pointer->next->next;
      queue.pop();
      stack.pop();
    }

    if (length % 2) {
      pointer->next = queue.front();
      pointer = pointer->next;
    }

    pointer->next = NULL;
  }
};