#include <queue>
#include <string>

using namespace std;
/**
 * 看起來蠻有趣的骨牌題
 *
 * R 表示往右倒，L 表示往左倒，問倒完的情況
 *
 * R..L => RRLL
 * R...L => RR.LL，同時左右倒過來會抵銷
 *
 * 已經倒下的骨牌，就不用處理吧
 */

/**
 * 先掃一遍？目前位置與下個位置做決定？
 * R..L  => RRLL
 * R...L => RR.LL
 * L...L => LLLLL
 * R...R => RRRRR
 * L...R => L...R
 *
 */

class Solution {
 public:
  string pushDominoes(string dominoes) {
    int size = dominoes.size();
    char cs[size + 1];
    cs[size] = '\0';
    queue<int> q;

    for (int i = 0; i < size; i++) {
      const char& c = dominoes[i];
      cs[i] = c;

      if (c == 'L' || c == 'R') {
        q.push(i);
      }
    }

    if (q.empty()) return dominoes;

    int begin = q.front();
    // 開頭遇到骨牌迎面而來
    if (dominoes[begin] == 'L') {
      for (int i = 0; i < begin; i++) {
        cs[i] = 'L';
      }
    }

    q.pop();

    while (!q.empty()) {
      int end = q.front();

      // L...R => L...R
      if (dominoes[begin] == 'L' && dominoes[end] == 'R') {
        // 沒有骨牌倒下，什麼都不用做
      }

      // L...L => LLLLL, R...R => RRRRR
      if (dominoes[begin] == dominoes[end]) {
        for (int i = 1; begin + i < end; i++) {
          cs[begin + i] = dominoes[begin];
        }
      }

      // R..L => RRLL, R...L => RR.LL
      if (dominoes[begin] == 'R' && dominoes[end] == 'L') {
        int between = end - begin + 1;
        int i = 1;

        while (begin + i < begin + (between / 2)) {
          cs[begin + i] = 'R';
          i++;
        }

        if (between % 2 == 1) {
          cs[begin + i] = '.';
          i++;
        }

        while (begin + i < end) {
          cs[begin + i] = 'L';
          i++;
        }
      }

      begin = end;
      q.pop();
    }

    if (dominoes[begin] == 'R') {
      for (int i = begin + 1; i < size; i++) {
        cs[i] = 'R';
      }
    }

    return string(cs);
  }
};