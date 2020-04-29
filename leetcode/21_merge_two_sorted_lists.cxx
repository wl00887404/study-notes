#include <iostream>

#include "./ListNode.cxx"
using namespace std;

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head = ListNode(0);
    ListNode* p = &head;

    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      };

      p = p->next;
    }

    if (l1 != NULL && l2 == NULL) {
      p->next = l1;
    } else if (l1 == NULL && l2 != NULL) {
      p->next = l2;
    }

    return head.next;
  }
};