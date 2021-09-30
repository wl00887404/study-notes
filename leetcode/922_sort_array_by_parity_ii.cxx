#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int size = nums.size();
    queue<int> waitForOdd;
    queue<int> waitForEven;

    for (int i = 0; i < size; i++) {
      queue<int>* waitFor = i % 2 ? &waitForEven : &waitForOdd;
      if (i % 2 != nums[i] % 2) {
        waitFor->push(i);
      }
    }

    while (!waitForOdd.empty() && !waitForEven.empty()) {
      swap(nums[waitForOdd.front()], nums[waitForEven.front()]);

      waitForOdd.pop();
      waitForEven.pop();
    }

    return nums;
  }

 private:
  void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
  }
} solution;

int main() {
  vector<int> nums = {4, 2, 5, 7};

  solution.sortArrayByParityII(nums);

  for (int& num : nums) {
    cout << num << endl;
  }

  return 0;
}