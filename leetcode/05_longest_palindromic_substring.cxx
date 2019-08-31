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
        int j = 0;
        int to = i + length - 1;
        
        while (true)
        {
          if (s[i + j] != s[to - j])
            break;

          if ((i + j) == (to - j) || (i + j + 1) == (to - j))
            return s.substr(i, length);

          j++;
        }
      }
    }

    return string({s[0]});
  }
} solution;

int main()
{
  cout << solution.longestPalindrome("babad") << endl;  // bab
  cout << solution.longestPalindrome("cbbd") << endl;   // bb
  cout << solution.longestPalindrome("ac") << endl;     // a
  cout << solution.longestPalindrome("ccc") << endl;    // ccc
  cout << solution.longestPalindrome("abcba") << endl;  // abcba
  cout << solution.longestPalindrome("abacab") << endl; // bacab
  cout << solution.longestPalindrome("zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir") << endl;

  return 0;
}