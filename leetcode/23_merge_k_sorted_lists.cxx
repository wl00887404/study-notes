#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 740 ms 笑死 有夠慢
 * 時間複雜度應該是 lists.size() * max(list[i].size())
 * testcase 應該 lists.size() 非常大吧
 *
 * 用 unordered_map 將同樣的 val 的目標先串起來: 36 ms
 * 全部先讀取出來: 32 ms
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
    vector<int> keys;
    unordered_map<int, ListNode*> headMap;  // (val, head)
    unordered_map<int, ListNode*> lastMap;  // (val, last)
    bool isFinished = false;

    for (int i = 0; i < length; i++) {
      while (lists[i] != NULL) {
        ListNode* originalNext = lists[i]->next;

        if (headMap.count(lists[i]->val)) {
          lists[i]->next = headMap[lists[i]->val];
          headMap[lists[i]->val] = lists[i];
        } else {
          headMap[lists[i]->val] = lists[i];
          lastMap[lists[i]->val] = lists[i];
          keys.push_back(lists[i]->val);
        }

        lists[i] = originalNext;
      }
    }

    sort(keys.begin(), keys.end());
    ListNode* p = &head;

    for (int key : keys) {
      p->next = headMap[key];
      p = lastMap[key];
    }

    p->next = NULL;

    return head.next;
  }
} solution;

class ReadAllSolution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int length = lists.size();

    if (length == 0) return 0;
    if (length == 1) return lists[0];

    vector<int> values;

    for (int i = 0; i < length; i++) {
      while (lists[i] != NULL) {
        values.push_back(lists[i]->val);
        lists[i] = lists[i]->next;
      }
    }

    ListNode head = ListNode(0);
    sort(values.begin(), values.end());
    ListNode* p = &head;

    for (int value : values) {
      p->next = new ListNode(value);
      p = p->next;
    }

    p->next = NULL;

    return head.next;
  }
};

int main() {
  // ListNode* l1 = new ListNode(1);
  // l1->next = new ListNode(4);
  // l1->next->next = new ListNode(5);

  // ListNode* l2 = new ListNode(1);
  // l2->next = new ListNode(3);
  // l2->next->next = new ListNode(4);

  // ListNode* l3 = new ListNode(2);
  // l3->next = new ListNode(6);

  // vector<ListNode*> lists = {l1, l2, l3};
  // ListNode* p = solution.mergeKLists(lists);

  ListNode* l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(2);

  ListNode* l2 = new ListNode(1);
  l2->next = new ListNode(1);
  l2->next->next = new ListNode(2);

  vector<ListNode*> lists = {l1, l2};
  ListNode* p = solution.mergeKLists(lists);

  while (p != NULL) {
    cout << p->val << endl;
    p = p->next;
  }

  return 0;
}