#include <iostream>
#include <vector>
using namespace std;

/**
 * A 到下一個 A 有多遠？
 * 消耗 k 增加距離
 *
 * 沒有下一個點
 * skipChance 不夠到下一個點
 * skipChance 足夠到下一個點
 */

/**
 * https://www.youtube.com/watch?v=00FmUN1pkGE
 * 原來是 slide window 解...
 * window 往右移動
 * 同時紀錄 window 內字的出現次數
 * 每當 window 長度 - 現在出現最多次數的字 < k
 * 頭往後移動且更新 window 內字的出現次數
 *
 * TODO: 實作它
 */

class Solution {
 public:
  int characterReplacement(string s, int k) {
    int length = s.length();
    vector<int> positionsByLetter[26];  // 依據字母的位置列

    int maxIndex = 0;  // 出現最多次的字母
    int maxTimes = 0;  // 出現最多的次數
    for (int i = 0; i < length; i++) {
      int letter = s[i] - 'A';
      positionsByLetter[letter].push_back(i);
      int times = positionsByLetter[letter].size();
      if (times > maxTimes) {
        maxTimes = times;
        maxIndex = letter;
      }
    }

    return getMaxLength(positionsByLetter[maxIndex], k, length);
  }

 private:
  int getMaxLength(vector<int>& positions, int& k, int& limit) {
    int length = positions.size();
    if (length == 0) return 0;
    if (length == 1) return k + 1;

    int maxLength = 0;

    for (int i = 0; i < length - 1; i++) {
      int result = 1;
      int skipChance = k;
      int from = positions[i];
      for (int j = i + 1; j < length; j++) {
        int distance = positions[j] - from - 1;
        if (distance != 0 && skipChance == 0) break;
        if (distance > skipChance) {
          result += skipChance;
          skipChance = 0;
        } else {
          skipChance -= distance;
          result += distance + 1;
          from = positions[j];
        }
      }

      result += skipChance;
      if (result >= limit) return limit;
      if (result > maxLength) maxLength = result;
    }

    return maxLength;
  }
} solution;

int main() {
  cout << solution.characterReplacement("AABABBA", 1) << endl;

  return 0;
}