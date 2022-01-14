#include <iostream>

#include "./ListNode.cxx"
using namespace std;

/**
 * 往下看不小心看到是 merge sort
 * 我也沒辦法
 */

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode* first = sortList(slow->next);
    slow->next = NULL;
    ListNode* second = sortList(head);

    ListNode dummyHead = ListNode(0);
    ListNode* pointer = &dummyHead;

    while (first != NULL && second != NULL) {
      if (first->val < second->val) {
        pointer->next = first;
        first = first->next;
      } else {
        pointer->next = second;
        second = second->next;
      }
      pointer = pointer->next;
    }

    pointer->next = first != NULL ? first : second;

    return dummyHead.next;
  }
};