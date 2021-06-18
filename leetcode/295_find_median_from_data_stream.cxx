#include <iostream>
using namespace std;

/**
 * 用雙向 linked list
 * TODO: 研究一下 Heap 解
 */

struct DoublyListNode {
  int value;
  DoublyListNode* prev;
  DoublyListNode* next;
  DoublyListNode(int value) : value(value), prev(NULL), next(NULL){};
};

class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    DoublyListNode* newNode = new DoublyListNode(num);

    if (length == 0) {
      median = newNode;
      length++;
      return;
    }

    insert(newNode);
    bool isOdd = length % 2;
    length++;
    if (isOdd && median->value > num) {
      median = median->prev;
      return;
    }

    if (!isOdd && median->value <= num) {
      median = median->next;
      return;
    }
  }

  double findMedian() {
    DoublyListNode* p = median;
    bool isOdd = length % 2;

    if (isOdd) return median->value;

    return (median->value + median->next->value) / 2.0;
  }

 private:
  int length = 0;
  DoublyListNode* median;

  void insert(DoublyListNode* newNode) {
    DoublyListNode* p = median;
    while (true) {
      // 一樣大插在 next
      if (p->value <= newNode->value) {
        if (p->next == NULL || newNode->value < p->next->value) {
          DoublyListNode* originNext = p->next;
          p->next = newNode;
          if (originNext) originNext->prev = newNode;
          newNode->prev = p;
          newNode->next = originNext;
          return;
        }

        p = p->next;
      } else {
        if (p->prev == NULL || p->prev->value < newNode->value) {
          DoublyListNode* originPrev = p->prev;
          p->prev = newNode;
          if (originPrev) originPrev->next = newNode;
          newNode->prev = originPrev;
          newNode->next = p;
          return;
        }
        p = p->prev;
      }
    }
  }
};
