
#include <iostream>
#include <unordered_set>

using namespace std;
/**
 * 這題沒辦法貪婪，只能全部都檢查
 * hash 字串時有點問題
 *   0 => 0, a => 1, b => 2, ... , z => 26
 *   a0 => 27, aa => 28
 * 應該是這樣吧
 */

class Solution {
 public:
  int maxUniqueSplit(string s) {
    sp = &s;
    size = s.size();

    return helper(0);
  }

  int size;
  string* sp;
  unordered_set<int> set;

  int helper(int i) {
    string& s = *sp;
    unsigned long long hashValue = 0;
    int result = 0;
    int oi = i;
    while (i < size) {
      hashValue = hashValue * 27 + (s[i] - 'a' + 1);

      // 已經有這個 substring 了
      if (set.count(hashValue)) {
        i++;
        continue;
      }

      set.insert(hashValue);

      // 檢查下一個 substring
      result = max(result, 1 + helper(i + 1));

      set.erase(hashValue);
      i++;
    }

    return result;
  }
};