#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "./ListNode.cxx"
#include "./log.cxx"
using namespace std;

/**
 * 740 ms 笑死 有夠慢
 * 時間複雜度應該是 lists.size() * max(list[i].size())
 * testcase 應該 lists.size() 非常大吧
 *
 * 用 unordered_map 將同樣的 val 的目標先串起來: 36 ms
 * 全部讀取出來: 32 ms
 *
 * unordered_map 與全部讀出來
 * 時間差不多 效能應該差在排序上
 *
 * 用 insert 的不會比較快 慘慘慘
 *
 * T1 解是兩個兩個合併耶
 * 但測試之後也是 32ms 應該也是 O(nlog n)
 */

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head = ListNode(0);
    ListNode* p = &head;

    while (l1 != NULL && l2 != NULL) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      };

      p = p->next;
    }

    if (l1 != NULL && l2 == NULL) {
      p->next = l1;
    } else if (l1 == NULL && l2 != NULL) {
      p->next = l2;
    }

    return head.next;
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int length = lists.size();

    if (length == 0) return 0;
    if (length == 1) return lists[0];

    while (length != 1) {
      for (int i = 0; i < length / 2; i++) {
        lists[i] = mergeTwoLists(lists[i], lists[length - i - 1]);
      }

      length = length / 2 + length % 2;
    }

    return lists[0];
  }
} solution;

class ReadAllSolution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int length = lists.size();

    if (length == 0) return 0;
    if (length == 1) return lists[0];

    vector<int> values;
    ListNode head = ListNode(0);
    ListNode* p = &head;

    for (int i = 0; i < length; i++) {
      while (lists[i] != NULL) {
        values.push_back(lists[i]->val);
        p->next = lists[i];
        p = p->next;
        lists[i] = lists[i]->next;
      }
    }

    sort(values.begin(), values.end());
    p = &head;

    for (int value : values) {
      p = p->next;
      p->val = value;
    }

    return head.next;
  }
};

int main() {
  ListNode* l1 = new ListNode({1, 4, 5});
  ListNode* l2 = new ListNode({1, 3, 4});
  ListNode* l3 = new ListNode({2, 6});
  vector<ListNode*> lists1 = {l1, l2, l3};

  log(solution.mergeKLists(lists1));

  ListNode* l4 = new ListNode({1, 2, 2});
  ListNode* l5 = new ListNode({1, 1, 2});
  vector<ListNode*> lists2 = {l4, l5};

  log(solution.mergeKLists(lists2));

  return 0;
}