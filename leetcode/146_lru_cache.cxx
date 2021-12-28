
/**
 * 經典結構
 * 直接看得答案：
 * https://josephjsf2.github.io/data/structure/and/algorithm/2020/05/09/LRU.html
 */
#include <iostream>
#include <unordered_map>

using namespace std;

struct MyListNode {
  MyListNode* next = NULL;
  MyListNode* prev = NULL;
  int value;
  int key;

  MyListNode() {}
  MyListNode(int& key, int& value) {
    this->key = key;
    this->value = value;
  }
};

class LRUCache {
 public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    head->next = last;
    last->prev = head;
  }

  int get(int key) {
    // 找不到回傳 -1
    if (!map.count(key)) return -1;

    // 使用後要更新順序
    // 從原本的位置移除
    map[key]->prev->next = map[key]->next;
    map[key]->next->prev = map[key]->prev;

    // 新增到最後
    map[key]->prev = last->prev;
    map[key]->next = last;
    last->prev->next = map[key];
    last->prev = map[key];

    return map[key]->value;
  }

  void put(int key, int value) {
    bool hasKey = map.count(key);

    if (!hasKey) {
      // 沒有這個 key 要新增節點
      map[key] = new MyListNode(key, value);
    } else {
      // 有這個 key 直接改值
      map[key]->value = value;
      // 並且為了之後插到最後
      // 先將他移除
      map[key]->prev->next = map[key]->next;
      map[key]->next->prev = map[key]->prev;
    }

    // 把更動的節點移到最後面
    map[key]->prev = last->prev;
    map[key]->next = last;
    last->prev->next = map[key];
    last->prev = map[key];

    if (hasKey) return;

    if (count + 1 < capacity) {
      count++;
      return;
    }

    // 如果新加入節點會超過容量
    // 刪除最舊的節點
    MyListNode* toBeRemoved = head->next;

    toBeRemoved->prev->next = toBeRemoved->next;
    toBeRemoved->next->prev = toBeRemoved->prev;
    map.erase(toBeRemoved->key);
    delete toBeRemoved;
  }

 private:
  int capacity;
  int count = 0;
  unordered_map<int, MyListNode*> map;
  MyListNode* head = new MyListNode();
  MyListNode* last = new MyListNode();
};
