#include <iostream>
#include <stack>

#include "./ListNode.cxx"
using namespace std;

/**
 * TODO: 研究 model answer
 */

/**
 * 2021/10/7
 * 後進先出看起來是 stack 吧
 * 這題是真的蠻簡單的
 */

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    stack<ListNode*> stack;
    ListNode* dummyHead = new ListNode();
    dummyHead->next = head;
    helper(dummyHead, head, k, stack);

    return dummyHead->next;
  }

  void helper(ListNode* before, ListNode* head, int& k,
              stack<ListNode*>& stack) {
    ListNode* pointer = head;

    for (int i = 0; i < k; i++) {
      if (pointer == NULL) return;
      stack.push(pointer);
      pointer = pointer->next;
    }

    pointer = before;
    ListNode* after = stack.top()->next;

    while (!stack.empty()) {
      pointer->next = stack.top();
      pointer = pointer->next;
      stack.pop();
    }

    pointer->next = after;
    helper(pointer, after, k, stack);
  }
};

class OldSolution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k < 2) return head;
    if (head == NULL || head->next == NULL) return head;

    ListNode* prev = head;
    ListNode* p = prev->next;
    ListNode* next = p->next;

    int i = 0;
    while (i < k - 1 && p != NULL) {
      p->next = prev;
      i++;

      prev = p;
      p = next;
      next = p == NULL ? p : p->next;
    }

    head->next = reverseKGroup(p, k);

    /**
     * i = 1.... k-1
     *
     * 1 == 交換 1 次
     * 需交換 k - 1 次 如果比 k -1 次少
     * 表 reverse 失敗 要重新 reverse 回來
     *
     * 交換 1 次 表示有 2 個元素
     * 交換 2 次 表示有 3 個元素
     * 交換 i 次 表示有 i + 1 個元素
     */
    if (i < k - 1) return reverseKGroup(prev, i + 1);

    return prev;
  }
} solution;

int main() {
  ListNode* p = new ListNode({1, 2, 3, 4, 5});

  log(solution.reverseKGroup(p, 3));

  return 0;
}