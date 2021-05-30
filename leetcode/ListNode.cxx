#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(vector<int> xs) {
    vector<int>::iterator begin = xs.begin();
    vector<int>::iterator end = xs.end();
    ListNode l = ListNode(begin, end);

    val = l.val;
    next = l.next;
  }
  ListNode(vector<int>::iterator begin, vector<int>::iterator end) {
    val = *(begin++);
    next = begin == end ? NULL : new ListNode(begin, end);
  }
};

void log(ListNode* head) {
  if (head == NULL) {
    cout << "[]" << endl;
    return;
  }

  cout << "[ ";

  while (head != NULL) {
    cout << head->val;

    if (head->next != NULL) cout << ", ";

    head = head->next;
  }

  cout << " ]" << endl;
}