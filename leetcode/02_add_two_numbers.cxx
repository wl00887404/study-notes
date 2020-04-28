#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1->val == 0 && l1->next == NULL) return l2;
    if (l2->val == 0 && l2->next == NULL) return l1;

    ListNode *head = new ListNode(0);
    ListNode *pointer = head;
    ListNode *prev = NULL;

    while (l1 != NULL || l2 != NULL) {
      ListNode *next = new ListNode(0);

      int val1 = l1 == NULL ? 0 : l1->val;
      int val2 = l2 == NULL ? 0 : l2->val;

      int val = val1 + val2 + pointer->val;

      if (val > 9) {
        next->val += 1;
        val %= 10;
      }

      pointer->val = val;

      l1 = l1 == NULL ? l1 : l1->next;
      l2 = l2 == NULL ? l2 : l2->next;
      pointer->next = next;
      prev = pointer;
      pointer = pointer->next;
    }

    if (pointer->val == 0) prev->next = NULL;

    return head;
  }
} solution;

int main() { return 0; }
