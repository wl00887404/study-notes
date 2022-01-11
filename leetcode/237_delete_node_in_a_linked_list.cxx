#include <iostream>

#include "./ListNode.cxx"

using namespace std;

/**
 * 其實我覺得蠻有創意的
 */

class Solution {
 public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};