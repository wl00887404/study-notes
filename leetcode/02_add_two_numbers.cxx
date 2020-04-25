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
    if (l1->val == 0 && l1->next == nullptr) return l2;
    if (l2->val == 0 && l2->next == nullptr) return l1;

    ListNode *head = new ListNode(0);
    ListNode *pointer = head;
    ListNode *prev = nullptr;

    while (l1 != nullptr || l2 != nullptr) {
      ListNode *next = new ListNode(0);

      int val1 = l1 == nullptr ? 0 : l1->val;
      int val2 = l2 == nullptr ? 0 : l2->val;

      int val = val1 + val2 + pointer->val;

      if (val > 9) {
        next->val += 1;
        val %= 10;
      }

      pointer->val = val;

      l1 = l1 == nullptr ? l1 : l1->next;
      l2 = l2 == nullptr ? l2 : l2->next;
      pointer->next = next;
      prev = pointer;
      pointer = pointer->next;
    }

    if (pointer->val == 0) prev->next = nullptr;

    return head;
  }
} solution;

int main() { return 0; }
