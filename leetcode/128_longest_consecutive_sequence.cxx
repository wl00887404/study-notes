#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 這題用 sort 反而是最快的
 * 說好的 O(n) 呢？
 *
 * hash table 數量太大
 * 效能太差了
 */

/**
 * sort 比我自己寫的 quicksort 還有快耶
 * 
 * 2021/6/17
 * 內建的 sort 是使用內省排序 Introsort
 * 可以保證 O(n log n)
 * TODO: https://liam.page/2018/08/29/introspective-sort/
 */

struct Interval {
  int begin;
  int end;
  Interval(int& begin) : begin(begin), end(begin + 1) {}
  Interval(int& begin, int& end) : begin(begin), end(end) {}
};

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    unordered_map<int, Interval*> waitForLeftNum;
    unordered_map<int, Interval*> waitForRightNum;
    int result = 0;

    for (int& num : nums) {
      if (set.count(num)) continue;
      set.insert(num);

      bool isWaitedForLeftNum = waitForLeftNum.count(num);
      bool isWaitedForRightNum = waitForRightNum.count(num);
      Interval* current;

      if (!isWaitedForLeftNum && !isWaitedForRightNum) {
        // 與所有區間獨立
        current = new Interval(num);
        waitForLeftNum[num - 1] = current;
        waitForRightNum[num + 1] = current;
      } else if (!isWaitedForRightNum) {
        // 為某區間的左側
        current = waitForLeftNum[num];
        current->begin = num;
        waitForLeftNum[num - 1] = current;
        waitForLeftNum.erase(num);
      } else if (!isWaitedForLeftNum) {
        // 為某區間的右側
        current = waitForRightNum[num];
        current->end = num + 1;
        waitForRightNum[num + 1] = current;
        waitForLeftNum.erase(num);
      } else {
        // 兩邊都有
        current = waitForLeftNum[num];
        current->begin = waitForRightNum[num]->begin;
        waitForLeftNum[current->begin - 1] = current;
        waitForRightNum.erase(num);
        waitForLeftNum.erase(num);
      }

      result = max(result, current->end - current->begin);
    }

    return result;
  }
} solution;

class OnlySetSolution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set;
    set.reserve(nums.size());

    for (int& num : nums) set.insert(num);

    int result = 0;
    for (const int& num : set) {
      if (set.count(num - 1)) continue;
      int i = 1;

      while (set.count(num + i)) i++;

      result = max(result, i);
    }

    return result;
  }
};

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

class SortSolution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int length = nums.size();
    if (length == 0) return 0;

    quickSort(nums.begin(), nums.end());

    int result = 1;
    int nextResult = 1;
    for (int i = 1; i < length; i++) {
      if (nums[i] == nums[i - 1] + 1) {
        nextResult++;
        result = max(result, nextResult);
      } else if (nums[i] == nums[i - 1]) {
      } else {
        nextResult = 1;
      }
    }

    return result;
  }
};

int main() {
  vector<int> nums = {100, 4, 200, 1, 3, 2};

  solution.longestConsecutive(nums);

  return 0;
}