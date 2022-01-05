#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * 這題麻煩的點在不知道 random 指的是誰
 * 直接一個 map 可以解決
 * key 直接是指標記憶體位置
 *
 * 不過我不太知道其他語言要怎麼解決這個問題
 * 發號碼排吧
 */

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;

    // original, clone
    unordered_map<Node*, Node*> map;
    Node* dummyHead = new Node(0);
    Node* prev = dummyHead;
    Node* pointer = head;

    while (pointer) {
      Node* node = new Node(pointer->val);
      prev->next = node;
      map[pointer] = node;

      prev = node;
      pointer = pointer->next;
    }

    pointer = head;

    while (pointer) {
      if (pointer->random) {
        map[pointer]->random = map[pointer->random];
      }

      pointer = pointer->next;
    }

    return dummyHead->next;
  }
};