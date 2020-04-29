#include <iostream>

#include "./ListNode.cxx"
using namespace std;

/**
 * 1 => 2 => 3 => 4
 * 1 => 3 => 2 => 4
 *
 * temp = 2
 * 1 => 3
 * 2 => 4 (1->next->next)
 * 3 (1->next) => 2
 */

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode dummyHead = ListNode(0);
    ListNode* p = &dummyHead;

    dummyHead.next = head;

    while (p->next != NULL && p->next->next != NULL) {
      ListNode* q = p->next;

      p->next = q->next;
      q->next = p->next->next;
      p->next->next = q;

      p = p->next->next;
    }

    return dummyHead.next;
  }
} solution;

int main() {
  ListNode* l1 = new ListNode({1, 2, 3, 4, 5});

  log(solution.swapPairs(l1));

  return 0;
}