#include <iostream>
#include <vector>
using namespace std;

/*
 * 實作一下 kmp 吧
 * https://youtu.be/cgaPEsMJkSc?t=3116
 * 
 * 已經 match 的部份
 * 只 shift 1 還是一樣不會 match
 * AGCCTAGCTCATT
 * AGCGG
 *    AGCGG
 * 
 * AGCCTAGCTCATT
 * AGCCTAC
 * ^    ^
 *      AGCCTAC
 * 
 * AGCCTAGCTCATT
 * AGCCGAGC
 * ^^   ^^
 *      AGCCGAGC
 * 
 * [   t   ][x]
 * [z][a][z][y]
 *       [z][a][z][y]
 * 
 * fail array 是找跟開頭有多少重複的部份
 * a b a b a c a
 * 0 0 1 2 3 0 1
 */

class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    if (needle == "")
      return 0;

    int fail[needle.length()] = {0};

    int weight = 0;
    int i = 1;

    while (i < needle.length())
    {
      if (needle[i] == needle[weight])
      {
        weight++;
        fail[i] = weight;
        i++;
        continue;
      }

      if (weight == 0)
      {
        i++;
        continue;
      }

      weight--;
    }

    i = 0;
    int j = 0;
    while (i < haystack.length())
    {
      if (haystack[i] == needle[j])
      {
        if (j == needle.length() - 1)
          return i - needle.length() + 1;

        j++;
        i++;
        continue;
      }

      if (j > 0)
      {
        j = fail[j - 1];
        continue;
      }

      i++;
    }

    return -1;
  }
} solution;

int main()
{
  // cout << solution.strStr("bacbabababacaab", "ababaca") << endl;
  // cout << solution.strStr("hello", "ll") << endl;
  // cout << solution.strStr("babba", "bbb") << endl;
  // cout << solution.strStr("aabaaabaaac", "aabaaac") << endl;
  cout << solution.strStr("mississippi", "issipi") << endl;

  return 0;
}