#include <iostream>
#include <unordered_set>

#include "./ListNode.cxx"
using namespace std;

/**
 * 討論區的解釋很棒
 * https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49789/My-accepted-simple-and-shortest-C%2B%2B-code-with-comments-explaining-the-algorithm.-Any-comments-or-improvements
 *
 * 如果某一個指標走完
 * 就換到另一個的頭
 * List1 = A + C
 * List2 = B + C
 *
 * 每一輪可以追上 |A - B|
 * 全部追上就會是 C 的開頭了
 *
 * TODO: 蠻特別的，以後再記一下
 */

class SetSolution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> set;

    ListNode *pointer = headA;
    while (pointer) {
      set.insert(pointer);

      pointer = pointer->next;
    }

    pointer = headB;
    while (pointer) {
      if (set.count(pointer)) {
        return pointer;
      }

      pointer = pointer->next;
    }

    return NULL;
  }
};