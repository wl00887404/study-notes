#include <iostream>

#include "./ListNode.cxx"
using namespace std;

/**
 * Follow up: Could you do it in O(n) time and O(1) space?
 *
 * ListNode 又沒有 prev
 * 是要怎麼 O(1) 啦
 *
 * 先用 fast 與 slow 找到中心點
 *
 * 1 2 3 4 $
 * s
 * f
 *   s f
 *
 * 1 2 3 4 5 $
 *     s   f
 * 
 * 想法與討論串那個一樣
 * https://leetcode.com/problems/palindrome-linked-list/discuss/64501/Java-easy-to-understand
 * 
 * 龜兔跑一輪，找到中心點
 * 中心點以後反轉，就可從最後跑回來
 * 另外反轉完要再反轉回去
 * 不然 judge 會死去 * 
 */

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head->next == NULL) return true;

    int size = 0;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
      size++;
    }

    // slow 現在是中間
    ListNode* prev = slow;
    size++;
    slow = slow->next;

    while (true) {
      ListNode* originalNext = slow->next;
      slow->next = prev;  // 將自己的下一個往回指
      prev = slow;
      if (!originalNext) break;
      slow = originalNext;
    }

    prev = NULL;
    bool result = true;
    while (size--) {
      if (result && slow->val != head->val) result = false;

      ListNode* originalNext = slow->next;
      slow->next = prev; // 反轉回去
      prev = slow;
      slow = originalNext;
      head = head->next;
    }

    return result;
  }
};