#include <iostream>

#include "./ListNode.cxx"
using namespace std;

class Solution {
 public:
  int getDecimalValue(ListNode* head) {
    ListNode*& pointer = head;
    int result = 0;

    while (pointer != NULL) {
      result <<= 1;
      result |= pointer->val;
      pointer = pointer->next;
    }

    return result;
  }
};