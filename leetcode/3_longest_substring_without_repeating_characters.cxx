#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * abcadedf
 *             from index length map[c]
 *   a         0    0     1
 *   ab        0    1     2
 *   abc       0    2     3
 * >  bca      1    3     3      0
 *    bcad     1    4     4
 *    bcade    1    5     5
 * >      ed   5    6     2      4
 *
 * 找到重複時
 *   deprecated = map[c] - from
 *   length = length - deprecated
 *           = length - map[c] + from
 *   from = map[c] + 1
 *
 * abba
 *         from  index length  map[c]
 *   a     0     0     1
 *   ab    0     1     2
 * >   b   2     2     1       1
 * >   ba  2     3     2
 */

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;
    int i = 0;
    int length = 0;
    int from = 0;
    int result = 0;

    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      
      if (map.count(c) && map[c] >= from) {
        if (length > result) result = length;

        length -= map[c] - from;
        from = map[c] + 1;
        map[c] = i;

        continue;
      }

      length++;
      map[c] = i;
    }

    return length > result ? length : result;
  }
} solution;

int main() {
  cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;         // 3
  cout << solution.lengthOfLongestSubstring("amqpcsrumjjufpu") << endl;  // 8
  cout << solution.lengthOfLongestSubstring("dvdf") << endl;             // 3
  cout << solution.lengthOfLongestSubstring("abba") << endl;             // 2

  return 0;
}