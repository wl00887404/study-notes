#include <iostream>

#include "./ListNode.cxx"
using namespace std;

/**
 * 同 287
 */

class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* turtle = head;
    ListNode* rabbit = head;

    do {
      turtle = turtle->next;
      if (rabbit->next == NULL || rabbit->next->next == NULL) return NULL;
      rabbit = rabbit->next->next;
    } while (turtle != rabbit);

    turtle = head;

    while (turtle != rabbit) {
      turtle = turtle->next;
      rabbit = rabbit->next;
    }

    return turtle;
  }
};