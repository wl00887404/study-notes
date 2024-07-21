#include <iostream>

#include "./ListNode.cxx"
using namespace std;

class Solution {
 public:
  ListNode* doubleIt(ListNode* head) {
    ListNode* pointer = head;

    while (pointer != NULL) {
      pointer->val *= 2;
      pointer = pointer->next;
    }

    if (head->val > 9) {
      ListNode* newHead = new ListNode(0);
      newHead->next = head;
      head = newHead;
    }

    pointer = head;

    while (pointer->next) {
      if (pointer->next->val > 9) {
        pointer->next->val -= 10;
        pointer->val += 1;
      }

      pointer = pointer->next;
    }

    return head;
  }
};