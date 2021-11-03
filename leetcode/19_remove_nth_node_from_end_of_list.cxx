#include <iostream>
#include <vector>

#include "./ListNode.cxx"
using namespace std;

/**
 * 我覺得這題是 easy
 * 最佳解用間隔 n 的兩個 pointer 蠻酷的
 */

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n == 0) return head;

    ListNode* p = head;
    int length = 0;

    while (p != NULL) {
      length++;
      p = p->next;
    }

    if (length == 1 || length == n) return head->next;

    p = head;
    int i = length - n - 2;

    while (i >= 0) {
      i--;
      p = p->next;
    }

    p->next = p->next->next;

    return head;
  }
} solution;

int main() {
  ListNode* p = new ListNode({1, 2, 3, 4, 5});

  log(solution.removeNthFromEnd(p, 2));

  return 0;
}