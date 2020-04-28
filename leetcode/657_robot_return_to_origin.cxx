#include <iostream>
using namespace std;

/**
 * https://medium.com/i-am-mike/javascript-%E7%9A%84-leetcode-%E6%BC%94%E7%AE%97%E4%B9%8B%E8%B7%AF-%E4%BA%8C-e4ce3f513c67
 * 這樣也一篇
 */

class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0;
    int y = 0;
    string::iterator begin = moves.begin();
    string::iterator end = moves.end();

    while (begin != end) {
      switch (*begin) {
        case 'R':
          x++;
          break;
        case 'L':
          x--;
          break;
        case 'U':
          y++;
          break;
        case 'D':
          y--;
          break;
      }
      
      begin++;
    }

    return x == 0 && y == 0;
  }
};