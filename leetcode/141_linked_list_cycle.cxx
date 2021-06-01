#include <iostream>

#include "./ListNode.cxx"
using namespace std;

class Solution {
 public:
  bool hasCycle(ListNode* head) {
    if (head == NULL) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    do {
      slow = slow->next;
      fast = fast->next != NULL ? fast->next->next : NULL;
      if (slow == NULL || fast == NULL) return false;
    } while (slow != fast);

    return true;
  }
};