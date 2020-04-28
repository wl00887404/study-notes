#include <iostream>
#include <vector>
using namespace std;

/**
 * 我覺得這題是 easy
 * T1 用間隔 n 的兩個 pointer 蠻酷的
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

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
  ListNode l1 = ListNode(1);
  ListNode l2 = ListNode(2);
  l1.next = &l2;
  ListNode l3 = ListNode(3);
  l2.next = &l3;
  ListNode l4 = ListNode(4);
  l3.next = &l4;
  ListNode l5 = ListNode(5);
  l4.next = &l5;

  ListNode* p = &l1;

  p = solution.removeNthFromEnd(p, 2);

  while (p) {
    cout << p->val << endl;
    p = p->next;
  }

  return 0;
}