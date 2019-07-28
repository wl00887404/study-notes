#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *head = new ListNode(0);
    ListNode *pointer = head;
    ListNode *prev = nullptr;

    while (l1 != nullptr || l2 != nullptr)
    {
      ListNode *next = new ListNode(0);
      
      int val1 = l1 == nullptr ? 0 : l1->val;
      int val2 = l2 == nullptr ? 0 : l2->val;

      int val = val1 + val2 + pointer->val;

      if (val > 9)
      {
        next->val += 1;
        val %= 10;
      }

      pointer->val = val;

      l1 = l1 == nullptr ? l1 : l1->next;
      l2 = l2 == nullptr ? l2 : l2->next;
      pointer->next = next;
      prev = pointer;
      pointer = pointer->next;
    }

    if (pointer->val == 0)
    {
      prev->next = nullptr;
    }

    return head;
  }
} solution;

class Console
{
public:
  Console() {}

  void log(ListNode *node)
  {
    cout << "[";
    while (node != nullptr)
    {
      cout << node->val;
      if (node->next != nullptr)
      {
        cout << ", ";
      }
      node = node->next;
    }
    cout << "]" << endl;
  }
} console;

int main()
{

  ListNode nodes1[] = {
      ListNode(2),
      ListNode(4),
      ListNode(3),
  };

  ListNode nodes2[] = {
      ListNode(5),
      ListNode(6),
      ListNode(4),
  };

  for (int i = 0; i < 2; i++)
  {
    nodes1[i].next = &nodes1[i + 1];
    nodes2[i].next = &nodes2[i + 1];
  }

  ListNode nodes3[] = {
      ListNode(5),
  };

  ListNode nodes4[] = {
      ListNode(5),
  };

  ListNode nodes5[] = {
      ListNode(1),
      ListNode(8),
  };

  nodes5[0].next = &nodes5[1];

  ListNode nodes6[] = {
      ListNode(0),
  };

  // [2, 4, 3] [5, 6, 4]
  console.log(nodes1);
  console.log(nodes2);
  console.log(solution.addTwoNumbers(nodes1, nodes2));

  // [5] [5]
  console.log(nodes3);
  console.log(nodes4);
  console.log(solution.addTwoNumbers(nodes3, nodes4));

  // [1, 8] [0]
  console.log(nodes5);
  console.log(nodes6);
  console.log(solution.addTwoNumbers(nodes5, nodes6));

  return 0;
}
