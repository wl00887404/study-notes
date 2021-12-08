#include <iostream>

#include "./ListNode.cxx"
using namespace std;

class OldSolution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode oh = ListNode(0);
    ListNode eh = ListNode(0);
    ListNode* op = &oh;
    ListNode* ep = &eh;
    ListNode* p = head;
    bool isOdd = true;

    while (p != NULL) {
      if (isOdd) {
        op->next = p;
        op = op->next;
      } else {
        ep->next = p;
        ep = ep->next;
      }

      p = p->next;
      isOdd = !isOdd;
    }

    ep->next = NULL;
    op->next = eh.next;

    return oh.next;
  }
};

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    bool isOdd = true;

    ListNode* oddHead = head;
    ListNode* evenHead = head->next;

    ListNode* oddPointer = head;
    ListNode* evenPointer = evenHead;
    ListNode* pointer = head->next->next;

    while (pointer != NULL) {
      ListNode*& whichPointer = isOdd ? oddPointer : evenPointer;

      whichPointer->next = pointer;
      whichPointer = whichPointer->next;
      pointer = pointer->next;
      isOdd = !isOdd;
    }

    oddPointer->next = evenHead;
    evenPointer->next = NULL;

    return oddHead;
  }
};