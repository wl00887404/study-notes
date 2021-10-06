#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 287 是只會重複一個點
 * 必定有結果，所以可以龜兔賽跑
 *
 * 出現機會只有一次或兩次是應該是關鍵
 * 只要有人出現兩次，就會造成有人缺席
 */

/**
 * 假設是 1, 2 ,3
 * 有可能出現的組合為
 * 一個重複 + 一個缺席
 * (1, 2) = 1, 1, 3 = 5
 * (1, 3) = 1, 1, 2 = 4
 * (2, 1) = 2, 2, 3 = 7
 * (2, 3) = 1, 2, 2 = 5
 * (3, 1) = 3, 3, 2 = 8
 * (3, 2) = 3, 3, 1 = 7
 *
 * 預期應該是 6
 * 所以可以得到多的元素減去缺乏元素的和
 * 好像沒什麼用
 */

/**
 * 想不出來直接看解答
 * https://ithelp.ithome.com.tw/articles/10185519
 *
 * 正負標記法很酷耶
 * 直接用 nums 標記
 * 出現過該 index 直接 * -1
 * 
 * 真的是太有創意了
 */

class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    unordered_set<int> set;

    for (int& num : nums) {
      if (set.count(num)) {
        result.push_back(num);
      } else {
        set.insert(num);
      }
    }

    return result;
  }
};

class ITHomeSolution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
      int num = abs(nums[i]);
      if (nums[num - 1] < 0) {
        result.push_back(num);
      } else {
        nums[num - 1] *= -1;
      }
    }

    return result;
  }
};