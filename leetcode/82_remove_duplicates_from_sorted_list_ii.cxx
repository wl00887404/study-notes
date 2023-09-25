#include <iostream>

#include "./ListNode.cxx"

using namespace std;

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummyHead = ListNode(101);
    dummyHead.next = head;
    ListNode* pointer = &dummyHead;

    // 檢查下一個節點是否要刪掉
    while (pointer != NULL && pointer->next != NULL) {
      const int& value = pointer->next->val;
      ListNode* nextPointer = pointer->next->next;
      
      while (nextPointer != NULL && nextPointer->val == value) {
        nextPointer = nextPointer->next;
      }

      if (pointer->next->next != nextPointer) {
        // 有重複的節點，直接省略 pointer->next
        pointer->next = nextPointer;
      }
      else{
        // 下一個節點沒有重複，直接往下
        pointer = pointer->next;
      }
    }

    return dummyHead.next;
  }
};