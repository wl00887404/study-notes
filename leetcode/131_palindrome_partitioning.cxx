#include <iostream>
#include <vector>

using namespace std;

/**
 * 找出所有的回文字串
 * 嘗試將他們組合在一起
 */

/**
 * 複習 5 囉
 *
 * c b b a b b c
 * 0 1 2 3 4 5 6
 *
 * ^ # c # b # b # a #  b  #  b  #  c  #  $
 * 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 *                 ^
 * 中心點在 7
 * (7 - 1) / 2 = 原本的位置
 * 往外拓 1, 3, 5, 7
 * 往外拓多少 = 回文字串長度
 *
 * i - radius 是最左側的 #
 * $_ + 1 是最左側的字元
 * ($_ - 2) / 2 回原本的位置
 * 最終結果 (i - radius - 1) / 2
 *
 */

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    size = s.size();
    int paddedSize = size * 2 + 3;
    char padded[paddedSize];

    padded[0] = '^';
    padded[paddedSize - 2] = '#';
    padded[paddedSize - 1] = '$';

    for (int i = 0; i < size; i++) {
      padded[i * 2 + 1] = '#';
      padded[i * 2 + 2] = s[i];
    }

    vector<string> array[size];
    palindromes = array;

    for (int i = 2; i < paddedSize - 2; i++) {
      int radius = 0;

      while (padded[i + radius + 1] == padded[i - radius - 1]) {
        radius++;
        if (padded[i + radius] == '#') {
          // 找到一組回文字串

          int begin = (i - radius - 1) / 2;
          palindromes[begin].push_back(s.substr(begin, radius));
        }
      }
    }

    helper(0);
    return result;
  }

  vector<vector<string>> result;
  int size;
  vector<string>* palindromes;
  vector<string> temp;

  void helper(int i) {
    if (i == size) return result.push_back(temp);

    for (string& s : palindromes[i]) {
      temp.push_back(s);
      helper(i + s.size());
      temp.pop_back();
    }
  }
};