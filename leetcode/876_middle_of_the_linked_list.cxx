#include <iostream>

#include "./ListNode.cxx"
using namespace std;

/**
 * | 1   | 2   | 3   | 4   | 5   | 6   |
 * | --- | --- | --- | --- | --- | --- |
 * | t   |     |     |     |     |     |
 * | r   |     |     |     |     |     |
 * |     | t   |     |     |     |     |
 * |     |     | r   |     |     |     |
 * |     |     | t   |     |     |     |
 * |     |     |     |     | r   |     |
 */

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    ListNode* turtle = head;
    ListNode* rabbit = head;

    while (rabbit->next && rabbit->next->next) {
      turtle = turtle->next;
      rabbit = rabbit->next->next;
    }

    if (rabbit->next) return turtle->next;

    return turtle;
  }
};