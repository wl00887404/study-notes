#include <iostream>
#include <queue>

#include "./ListNode.cxx"
using namespace std;

/**
 * 幹第一名就不是 insertion sort 機掰
 */

class Solution {
 public:
  ListNode* insertionSortList(ListNode* head) {
    queue<ListNode*> queue;

    ListNode* pointer = head;

    while (pointer) {
      queue.push(pointer);
      pointer = pointer->next;
    }

    ListNode* dummyHead = new ListNode(-5001);

    while (!queue.empty()) {
      insert(dummyHead, queue.front());
      queue.pop();
    }

    return dummyHead->next;
  }

  void insert(ListNode* head, ListNode* node) {
    ListNode* pointer = head;
    while (pointer->next && pointer->next->val < node->val) {
      pointer = pointer->next;
    }

    ListNode* temp = pointer->next;
    pointer->next = node;
    node->next = temp;
  }
};