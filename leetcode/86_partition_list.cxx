#include <iostream>

#include "./ListNode.cxx"
using namespace std;

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* lessHead = new ListNode();
    ListNode* greaterHead = new ListNode();

    ListNode* lessPointer = lessHead;

    ListNode* greaterPointer = greaterHead;
    ListNode* pointer = head;

    while (pointer != nullptr) {
      if (pointer->val >= x) {
        greaterPointer->next = pointer;
        greaterPointer = pointer;
      } else {
        lessPointer->next = pointer;
        lessPointer = pointer;
      }

      pointer = pointer->next;
    }

    lessPointer->next = greaterHead->next;
    greaterPointer->next = nullptr;

    return lessHead->next;
  }
};