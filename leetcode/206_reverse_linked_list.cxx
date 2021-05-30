#include <iostream>
#include <stack>

#include "./ListNode.cxx"
using namespace std;

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* pointer = head;
    stack<ListNode*> stack;

    while (pointer != NULL) {
      stack.push(pointer);
      pointer = pointer->next;
    }

    ListNode dummyHead = ListNode();
    pointer = &dummyHead;

    while (!stack.empty()) {
      pointer->next = stack.top();
      pointer = pointer->next;
      stack.pop();
    }

    pointer->next = NULL;

    return dummyHead.next;
  }
};