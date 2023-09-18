#include <iostream>
#include <vector>

using namespace std;

class SegmentTreeNode {
  int begin;
  int end;
  int max;
  int min;
  SegmentTreeNode* left;
  SegmentTreeNode* right;

 public:
  SegmentTreeNode(vector<int>& values, int begin, int end) {
    this->begin = begin;
    this->end = end;

    if (begin + 1 == end) {
      max = values[begin];
      min = values[begin];
      left = NULL;
      right = NULL;
      return;
    }

    int mid = (begin + end) / 2;

    left = new SegmentTreeNode(values, begin, mid);
    right = new SegmentTreeNode(values, mid, end);
    max = std::max(left->max, right->max);
    min = std::min(left->min, right->min);
  }

  const pair<int, int> query(int begin, int end) {
    if (begin == this->begin && end == this->end) {
      return make_pair(min, max);
    }

    int mid = (this->begin + this->end) / 2;

    if (begin >= mid) {
      return right->query(begin, end);
    }

    if (end <= mid) {
      return left->query(begin, end);
    }

    const pair<int, int>& leftResult = left->query(begin, mid);
    const pair<int, int>& rightResult = right->query(mid, end);

    return make_pair(std::min(leftResult.first, rightResult.first),
                     std::max(leftResult.second, rightResult.second));
  }
};
