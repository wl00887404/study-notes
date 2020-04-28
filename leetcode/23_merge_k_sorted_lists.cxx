#include <iostream>
#include <vector>
using namespace std;

/**
 * 740 ms 笑死 有夠慢
 * 時間複雜度應該是 lists.size() * max(list[i].size())
 * testcase 應該 lists.size() 非常大吧
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int length = lists.size();

    if (length == 0) return 0;
    if (length == 1) return lists[0];

    ListNode head = ListNode(0);
    ListNode* p = &head;

    while (true) {
      int j = -1;

      for (int i = 0; i < length; i++) {
        if (lists[i] == NULL) continue;
        if (j == -1 || lists[i]->val < lists[j]->val) j = i;
      }

      if (j == -1) break;

      p->next = lists[j];
      p = p->next;
      lists[j] = lists[j]->next;
    }

    return head.next;
  }
};