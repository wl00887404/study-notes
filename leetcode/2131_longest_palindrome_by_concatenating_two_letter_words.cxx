#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 給一堆字串，每個字串都是 2 個字元
 * 找到組合組合來最長
 *
 * 簡單 hash 每一個字串直接 (word[1] - 'a') * 26 + (word[0] - 'a')
 * 能跟他搭配的是 (word[0] - 'a') * 26 + (word[1] - 'a')
 * 找到一組就結果就可以 + 4
 *
 * 如果能找到一組，沒辦法跟別人搭配，但是自己重複的，像是 aa, xx
 * 就可以把他擺在中間，總長度可以再 + 2
 */

/**
 * 2025/5/26
 * 昨天太累了，結果每日一題沒寫到，哭了
 */

class Solution {
 public:
  int longestPalindrome(vector<string>& words) {
    unordered_map<int, int> map;
    int result = 0;

    for (string& s : words) {
      int value1 = (s[1] - 'a') * 26 + (s[0] - 'a');
      int value2 = (s[0] - 'a') * 26 + (s[1] - 'a');

      // 找不到配對
      if (map[value2] == 0) {
        map[value1]++;
        continue;
      }

      result += 4;
      map[value2]--;
    }

    for (int i = 0; i < 26; i++) {
      int value1 = i * 26 + i;

      if (map[value1] == 0) continue;

      result += 2;
      break;
    }

    return result;
  }
};