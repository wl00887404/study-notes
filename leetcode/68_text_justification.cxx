#include <iostream>
#include <vector>

using namespace std;
/**
 * 怎麼看起來沒難度
 * 不就貪心法看可以塞幾個字串在一行
 */

/**
 * 如果只有一個字串，或是最後一行，那就是靠左對齊
 * 如是兩個以上的字串，那就需要均分空白
 */

class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int size = words.size();
    int begin = 0;
    int end = 1;
    int remainWidth;

    while (begin < size) {
      // 先放一個字串進去
      remainWidth = maxWidth - words[begin].size();
      while (end < size) {
        // 放第二字串進去，至少要有一個空格
        remainWidth -= words[end].length() + 1;
        if (remainWidth < 0) {
          // 靠腰放失敗，把剛剛剪去的長度補回去
          remainWidth += words[end].length() + 1;
          break;
        }
        end++;  // 放成功了
      }

      // begin 到 end - 1 是一行
      string s = words[begin];
      begin++;
      // 這麼多個間隔，要分剩下的空白 remainWidth
      int remainWordCount = end - begin;

      // 只有一個字串或是最後一行，靠左對齊
      if (remainWordCount == 0 || end == size) {
        while (begin < end) {
          s += " " + words[begin];
          begin++;
        }
        int spaceCount = maxWidth - s.length();
        while (spaceCount--) s += " ";
      } else {
        // 每個間隔要多少空白
        int baseSpace = remainWidth / remainWordCount;
        // 幾個間隔要多一個空白
        int extraSpace = remainWidth % remainWordCount;
        while (begin < end) {
          int space = 1 + baseSpace + (extraSpace > 0 ? 1 : 0);
          while (space--) s += " ";
          s += words[begin];
          begin++;
          extraSpace--;
        }
      }

      result.push_back(s);
      begin = end;
      end++;
    }
    return result;
  }
};
