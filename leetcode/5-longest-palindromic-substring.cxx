#include <iostream>
using namespace std;

/*
 * 幹幹幹幹幹 終於看懂了
 * 要找的是 aba cdeedc 這種組合
 *  
 * from to length
 * 0    5  5
 * 0    4  4
 * 1    5  4
 */

class Solution
{
public:
  string longestPalindrome(string s)
  {
    if (s.length() == 0)
      return "";

    for (int length = s.length(); length > 1; length--)
    {
      for (int i = 0; i + (length - 1) < s.length(); i++)
      {
        if (isPalindrome(s, i, i + (length - 1)))
          return s.substr(i, length);
      }
    }

    return string({s[0]});
  }

  bool isPalindrome(string s, int from, int to)
  {
    while (true)
    {
      if (s[from] != s[to])
        return false;

      if (from == to || from + 1 == to)
        break;

      from++;
      to--;
    }

    return true;
  }
} solution;

int main()
{
  // cout << solution.longestPalindrome("babad") << endl;  // bab
  // cout << solution.longestPalindrome("cbbd") << endl; // bb
  // cout << solution.longestPalindrome("ac") << endl;     // a
  // cout << solution.longestPalindrome("ccc") << endl;    // ccc
  // cout << solution.longestPalindrome("abcba") << endl;  // a
  // cout << solution.longestPalindrome("abacab") << endl; // bacab
  cout << solution.longestPalindrome("zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir") << endl; // bacab
  // cout << solution.isPalindrome("aca", 0, 2) << endl;
  // cout << solution.isPalindrome("abcda", 0, 4) << endl;

  return 0;
}