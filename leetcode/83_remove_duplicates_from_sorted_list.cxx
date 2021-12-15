#include <iostream>

#include "./ListNode.cxx"
using namespace std;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* next = head->next;

    while (next != NULL && next->val == head->val) next = next->next;

    head->next = deleteDuplicates(next);

    return head;
  }
};