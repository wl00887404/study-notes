
#include <iostream>
#include <stack>

#include "ListNode.cxx"

using namespace std;

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    int reverseCount = right - left + 1;
    if (reverseCount == 1) return head;

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    left++;
    right++;
    ListNode* reverseHead = dummyHead;
    int i = 0;
    while (i < left - 2) {
      reverseHead = reverseHead->next;
      i++;
    }

    stack<ListNode*> stack;
    ListNode* pointer = reverseHead->next;

    while (reverseCount--) {
      stack.push(pointer);
      pointer = pointer != NULL ? pointer->next : NULL;
    }

    // 2 跟 5 接起來
    reverseHead->next->next = pointer;
    pointer = reverseHead;

    while (!stack.empty() && pointer != NULL) {
      pointer->next = stack.top();
      pointer = pointer->next;
      stack.pop();
    }

    return dummyHead->next;
  }
};