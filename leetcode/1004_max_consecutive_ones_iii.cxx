#include <iostream>
#include <vector>

using namespace std;

/**
 * 最貪的作法
 * 補 1 之後可以連接兩塊
 *
 * 一定是從最大的開始連接嗎？
 *
 * k = 3
 * 5   5     8
 *   3   100
 *
 * 最佳解應該是 5 + 3 + 5
 * 而非 8 + 3
 *
 * 有可能的答案：
 * 1. 自己往左右補格子
 * 2. 跟右邊結合
 *
 * 欸不對
 * 往右結合
 * 還可以往左補格子嗎？
 *
 * k = 3
 *    5   5
 * 10   1
 */

struct Node {
  int value = 0;
  int gap = 0;
  Node* next = NULL;
  Node* prev = NULL;
};

class GraphSolution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    size = nums.size();
    numsPointer = &nums;

    Node* head = new Node();
    buildNodes(head);

    int result = 0;
    while (head) {
      result = max(result, helper(head, k));
      head = head->next;
    }

    return result;
  }

  int helper(Node* node, int k) {
    int leftGap = node->prev ? node->prev->gap : 0;

    int result = 0;
    Node* pointer = node;

    // 往右連接
    while (pointer && pointer->gap <= k) {
      result += pointer->value + pointer->gap;
      k -= pointer->gap;
      pointer = pointer->next;
    }

    if (pointer) result += pointer->value;

    int rightGap = pointer ? pointer->gap : 0;

    return result + min(leftGap + rightGap, k);
  }

  vector<int>* numsPointer;
  int size;

  void buildNodes(Node* head) {
    Node* pointer = head;
    vector<int>& nums = *numsPointer;

    int i = 0;
    while (i < size) {
      while (i < size && nums[i] == 1) {
        pointer->value++;
        i++;
      }

      while (i < size && nums[i] == 0) {
        pointer->gap++;
        i++;
      }

      pointer->next = new Node();
      pointer->next->prev = pointer;
      pointer = pointer->next;
    }
  }
};

/**
 * 好啦 slide window
 */
class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int from = 0;
    int current = 0;
    int size = nums.size();
    int result = 0;

    while (current < size) {
      // 遇到坑
      if (nums[current] == 0) {
        // 嘗試填坑
        if (k > 0) {
          k--;
        } else {
          // 沒辦法填坑了
          result = max(result, current - from);
          // from 往後走找坑
          while (nums[from] != 0) from++;
          from++;
          // current 填坑
          // 所以 k 不用 ++
        }
      }

      // 全部走完
      result = max(result, current - from + 1);

      current++;
    }

    return result;
  }
};