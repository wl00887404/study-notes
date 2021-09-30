
#include <iostream>

#include "ListNode.cxx"

using namespace std;

class Solution {
 public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int length = 0;
    vector<ListNode*> nodes;
    ListNode* pointer = head;

    while (pointer != NULL) {
      length++;
      nodes.push_back(pointer);
      pointer = pointer->next;
    }

    int part = length / k;
    int shouldPlus1 = length % k;
    vector<ListNode*> result(k);

    int i = 0;
    for (int j = 0; j < k && i < length; j++) {
      result[j] = nodes[i];
      if (j != 0) nodes[i - 1]->next = NULL;

      i += part + (j < shouldPlus1 ? 1 : 0);
    }

    return result;
  }
};