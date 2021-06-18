#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>::iterator& iterator1, vector<int>::iterator& iterator2) {
  int temp = *iterator1;
  *iterator1 = *iterator2;
  *iterator2 = temp;
}

void quickSort(vector<int>::iterator begin, vector<int>::iterator end) {
  if (begin >= end) return;

  // pivot 是 0
  vector<int>::iterator left = begin + 1;
  vector<int>::iterator right = end - 1;

  while (true) {
    while (left < right && *left <= *begin) left++;
    while (*begin < *right) right--;

    if (left >= right) break;

    swap(left, right);
  }
  swap(begin, right);

  quickSort(begin, right);
  quickSort(right + 1, end);
}