#include <iostream>

#include "./ListNode.cxx"

using namespace std;

/**
 * 旋轉就是尾接到頭
 * 尾前面一位接到 null
 */

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) return head;

    int size = 0;
    ListNode* pointer = head;
    ListNode* last;

    // 算長度 + 找最後一位
    while (pointer != NULL) {
      size++;
      if (pointer->next == NULL) last = pointer;
      pointer = pointer->next;
    }

    k %= size;
    if (k == 0) return head; // 根本不用轉

    k = size - k;
    last->next = head;
    ListNode* prev;
    pointer = head;

    while (k--) {
      prev = pointer;
      pointer = pointer->next;
    }

    prev->next = NULL;

    return pointer;
  }
};