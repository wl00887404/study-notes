#include <iostream>

using namespace std;

/**
 * 3[a2[bc]d]2[e]
 *
 * 3 => 開始 parse a2[bc]d
 *   a + 2 => 開始 parse bc
 *   abcbcd
 *
 * 3[       ]2[ ]
 *   a     d   e
 *    2[bc]
 */
class Solution {
 public:
  string decodeString(string& s) {
    p = &s;
    size = s.size();

    return helper();
  }

  string* p;
  int size;
  int i = 0;

  string helper() {
    string& s = *p;
    string result = "";

    while (i < size && s[i] != ']') {
      if ('0' <= s[i] && s[i] <= '9') {
        result += parse();
      } else {
        result += s[i];
        i++;
      }
    }

    return result;
  }

  // parse 3[...]
  string parse() {
    string& s = *p;
    string result = "";

    int times = 0;
    for (; '0' <= s[i] && s[i] <= '9'; i++) {
      times = 10 * times + (s[i] - '0');
    }

    i++;  // 略過 [

    string substring = helper();

    i++;  // 略過 ]
    while (times--) result += substring;

    return result;
  }
};