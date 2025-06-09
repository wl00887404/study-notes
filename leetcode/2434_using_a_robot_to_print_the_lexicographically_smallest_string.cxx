#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/**
 * 有一個機器人，可以做兩種操作
 * 1. 把 s[0] 移動去 t[-1]
 * 2. 把 t[-1] 移動去答案
 *
 * 這個機器人就是 stack 嘛
 */

/**
 * stack 的操作下，先進後出
 * 哪些組合可能是辦不到的？
 * abcd
 *
 *  in,  in,  in,  in, out, out, out, out => dcba
 *  in,  in,  in, out,  in, out, out, out => cdba
 *  in,  in,  in, out, out,  in, out, out => cbda
 *  in,  in,  in, out, out, out,  in, out => cbad
 *  in,  in, out,  in,  in, out, out, out => bdca
 *  in,  in, out,  in, out,  in, out, out => bcda
 *  in,  in, out,  in, out, out,  in, out => bcad
 *  in,  in, out, out,  in,  in, out, out => badc
 *  in,  in, out, out   in, out,  in, out => bacd
 *  in, out,  in,  in,  in, out, out, out => adcb
 *  in, out,  in,  in, out,  in, out, out => acdb
 *  in, out,  in,  in, out, out,  in, out => acbd
 *  in, out,  in, out,  in,  in, out, out => abdc
 *  in, out,  in, out,  in, out,  in, out => abcd
 *
 * 沒有 adbc, bdac, cabd, cadb, cdab, dabc, dacb, dbac, dbca, dcab
 */

/**
 * 列一列之後沒什麼想法，哭呀
 *
 * 依據之前 skyline 題目的想法
 * a 被 push 進來，一定是馬上 pop 出去比較好
 * 假設 stack 有 [y] 遇到 x => 把 x push 進去
 * [y, x] 遇到 x => 把 x push 進去
 * [y, x, x] 遇到 y => x 在前面比較好，pop x x => push y
 */

/**
 * 策略失敗了
 * str = bdda
 * 會輸出 badd，正確答案是 addb
 *
 * 因為 b 一遇到 d 就會 pop
 * 但實際上要等到 a 出來再 pop
 *
 * 從後面開始記錄最小的字元呢？這樣就知道要不到等了
 *
 * 後面有比自己小的字元 => push 進去等他
 * 我就是那個在等的字元 => pop 出來
 *
 * str = bddabe, lessAfter = aaaabe
 * b => 在等 a => push => [b]
 * d => 在等 a => push => [b, d]
 * d => 在等 a => push => [b, d, d]
 * a => 不用等 => 輸出 a
 * b => 不用等 => 輸出 b
 * e => 不用等 => stack 比自己小 => pop * 3 => 輸出 e
 */

/**
 * testcase 46
 * str = vzhofnpo, lessAfter = fffffnoo
 *
 * v => 在等 f => push => [v]
 * z => 在等 f => push => [v, z]
 * h => 在等 f => push => [v, z, h]
 * o => 在等 f => push => [v, z, h, o]
 * f => 不用等 => 輸出 f
 * n => 不用等 => 輸出 n
 * p => 在等 o => stack 就有 o => pop => [v, z, h]
 */

class Solution {
 public:
  string robotWithString(string s) {
    stack<char> stack;
    int size = s.size();

    char result[size + 1];
    result[size] = '\0';

    char waitForChar[size];
    char minChar = s[size - 1];

    for (int i = size - 1; i >= 0; i--) {
      minChar = min(minChar, s[i]);
      waitForChar[i] = minChar;
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
      const char& c = s[i];
      const char& wc = waitForChar[i];
      //   cout << c << " " << waitFor << endl;

      // 在等的字元，剛好在 stack 裡！
      while (!stack.empty() && stack.top() <= wc) {
        // cout << "stack pop" << endl;
        result[j] = stack.top();
        stack.pop();
        j++;
      }

      if (wc == c) {
        result[j] = c;
        j++;
      } else {
        stack.push(c);
      }
    }

    while (!stack.empty()) {
      result[j] = stack.top();
      stack.pop();
      j++;
    }

    return string(result);
  }
};
