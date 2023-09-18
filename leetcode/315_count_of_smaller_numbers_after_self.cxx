#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 2023/9/18
 * FIXME: 未完成
 */

/**
 * 題意：某個 index 往右，比自己小的數值有幾個
 *
 * 第一次嘗試直接寫個暴力解
 * 欸幹不行喔
 */

/**
 * 洗澡時想了一下怎麼用排序解
 * 從右邊開始排序
 * 每個位置的值 = 在排序中的位置
 * 之後更新排序
 */

/**
 * 因為有排序
 * 所以想辦法做 binary search 的話
 * 無法知道前面較小項出現的次數
 * 插入更新還是需要 O(n) 才行
 */

/**
 * 記憶中位數怎麼樣？
 * 插入當比中位數還大的數字，中位數往右
 * 插入比中位數還小的數字，中位數往左
 *
 * 失敗了哭喔
 */

/**
 * FIXME:
 * 受不了
 * 還是看解答好了
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/445769/merge-sort-CLEAR-simple-EXPLANATION-with-EXAMPLES-O(n-lg-n)
 *
 * 最主要的問題是在計算比自己小的數字出現次數一定是 O(n)
 */

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int size = nums.size();

    return {};
  }
};

struct MyListNode {
  int value;
  int times;  // 出現次數
  MyListNode* next = NULL;
  MyListNode* prev = NULL;

  MyListNode(int value, int times) : value(value), times(times){};
};

// 插入排序法
class InsertSortSolution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int size = nums.size();
    MyListNode head = MyListNode(0, 0);

    vector<int> result(size, 0);

    for (int i = size - 1; 0 <= i; i--) {
      MyListNode* p = &head;

      while (p->next != NULL && p->next->value < nums[i]) {
        p = p->next;
        result[i] += p->times;
      }
      if (p->next->value == nums[i]) {
        p->next->times++;
      } else {
        MyListNode* newNode = new MyListNode(nums[i], 1);
        newNode->next = p->next;
        newNode->next->prev = newNode;
        newNode->prev = p;
        p->next = newNode;
      }
    }

    return result;
  }
};

// 使用中位數對半處理
class InsertSortWithMediumSolution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    int size = nums.size();
    MyListNode* head = new MyListNode(-10001, 0);
    MyListNode* last = new MyListNode(10001, 0);
    head->next = last;
    last->prev = head;
    MyListNode* medium = last;

    vector<int> result(size, 0);

    for (int i = size - 1; 0 <= i; i--) {
      MyListNode* p;

      if (medium->value < nums[i]) {
        p = head;

        while (p->next->value < nums[i]) {
          p = p->next;
          result[i] += p->times;
        }
      } else {
        p = last;
        result[i] = size - i - 1;

        while (p->prev->value >= nums[i]) {
          p = p->prev;
          result[i] -= p->times;
        }

        p = p->prev;
      }

      if (p->next->value == nums[i]) {
        p->next->times++;
      } else {
        MyListNode* newNode = new MyListNode(nums[i], 1);
        newNode->next = p->next;
        newNode->next->prev = newNode;
        newNode->prev = p;
        p->next = newNode;
      }

      if (medium->value < nums[i]) {
        medium = medium->next;
      } else {
        medium = medium->prev;
      }
    }

    return result;
  }
};