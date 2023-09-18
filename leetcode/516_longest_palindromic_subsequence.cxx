#include <iostream>
#include <vector>

using namespace std;


/**
 * 2023/9/18
 * FIXME: 未完成
 */

/**
 * 老 DP 寶了
 * 最長回文字串每個字元為中心，每個字串中間補 #
 * 往左右擴展，找到最長的回文字串
 * 序列就比較麻煩，因為序列可以不連續
 */

/**
 * 中心往外擴展，找到最長的回文字串
 * 但是序列是可以跳過字元的
 * 那不如直接產生一堆序列直接判斷
 */

/**
 * 等等等，以原本的演算法，往外擴張
 * 左右一樣 => 採用繼續擴張
 * 左右不一樣 => 選左邊、選右邊、兩邊都不選
 */

class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    vector<char> cs;
    int result = 0;
  }

  void padding(string& s, vector<char>& cs) {
    int length = s.length();
    int paddedLength = 2 * length + 3;
    char paddedS[paddedLength];
    paddedS[0] = '^';
    paddedS[1] = '#';
    paddedS[paddedLength - 1] = '$';

    for (int i = 0; i < length; i++) {
      paddedS[i * 2 + 2] = s[i];
      paddedS[i * 2 + 3] = '#';
    }
  }
};