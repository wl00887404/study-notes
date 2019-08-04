#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int totalLength = s.length();

    if (totalLength == 0)
      return 0;

    unordered_map<char, int> map;
    map[s[0]] = 0;
    int i = 1;
    int length = 1;
    int from = 0;
    int result = 0;

    while (i != totalLength)
    {

      if (map.count(s[i]) && map[s[i]] >= from)
      {
        if (length > result)
        {
          result = length;
        }

        length -= map[s[i]] - from;
        from = map[s[i]] + 1;
        map[s[i]] = i;
        i++;

        continue;
      }

      length++;
      map[s[i]] = i;
      i++;
    }

    return length > result ? length : result;
  }
} solution;

/* abcadedf
 *             from  index length map[x]
 *   a         0     0     1
 *   ab        0     1     2
 *   abc       0     2     3
 * >  bca      1     3     3      0
 *    bcad     1     4     4
 *    bcade    1     5     5
 * >      ed   5     6     2      4 
 * 
 * 找到重複時
 * 1. length = length - (map[x] - from + 1) + 1
 *           = length - map[x] + from 
 * 2. from = map[x] + 1
 * 
 * abba
 *         from  index length  map[x]
 *   a     0     0     1
 *   ab    0     1     2
 * >   b   2     2     1       1
 * >   ba  2     3     2
 */

int main()
{
  // cout << solution.lengthOfLongestSubstring("abcabcbb") << endl; // 3
  // cout << solution.lengthOfLongestSubstring("amqpcsrumjjufpu") << endl; // 8
  // cout << solution.lengthOfLongestSubstring("dvdf") << endl; // 3
  cout << solution.lengthOfLongestSubstring("abba") << endl; // 2

  return 0;
}