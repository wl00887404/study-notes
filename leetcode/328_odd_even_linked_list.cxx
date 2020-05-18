#include <iostream>

#include "./ListNode.cxx"
using namespace std;

class Solution {
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