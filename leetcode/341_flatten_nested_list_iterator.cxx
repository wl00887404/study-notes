#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

/**
 * 如果是存整數 ，那就取出下一個
 * 如果是存陣列，那就取出與現在的陣列串接
 *
 * 最麻煩就一直有塞空陣列進來
 * 這樣沒辦法判斷
 * 
 * 我想最佳解變成先找到 next 等著
 */

class NestedIterator {
 public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    vectorStack.push(&nestedList);
    indexStack.push(0);
    findNext();
  }

  void findNext() {
    while (!vectorStack.empty()) {
      const vector<NestedInteger> &list = *vectorStack.top();
      int &i = indexStack.top();

      if (i == list.size()) {
        vectorStack.pop();
        indexStack.pop();
        continue;
      }

      if (list[i].isInteger()) return;

      // 如果是 List
      const vector<NestedInteger> &nextList = list[i].getList();
      i++;

      if (nextList.empty()) continue;

      vectorStack.push(&nextList);
      indexStack.push(0);
    }
  }

  int next() {
    const vector<NestedInteger> &list = *vectorStack.top();
    int &i = indexStack.top();

    int result = list[i].getInteger();
    i++;

    findNext();

    return result;
  }

  bool hasNext() { return !vectorStack.empty(); }

  stack<const vector<NestedInteger> *> vectorStack;
  stack<int> indexStack;
};