#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  Solution(vector<int>& nums) {
    size = nums.size();
    numsPointer = &nums;

    shuffled.resize(size);

    for (int i = 0; i < size; i++) {
      shuffled[i] = nums[i];
    }
  }

  vector<int> reset() { return *numsPointer; }

  vector<int> shuffle() {
    int i = size;

    while (i--) {
      int j = rand() % (i + 1);
      int temp = shuffled[i];
      shuffled[i] = shuffled[j];
      shuffled[j] = temp;
    }

    return shuffled;
  }

  vector<int>* numsPointer;
  vector<int> shuffled;
  int size;
};
