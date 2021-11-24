#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
/**
 * 分為 word 與 puzzle
 * word 必須包含 puzzle 的第一個字母
 * 而且 word 出現的每一個字元 puzzle 都有
 *
 * Constraints 有提及
 * - puzzles[i].length == 7
 * - Each puzzles[i] does not contain repeated characters.
 * 這兩個應該是關鍵
 *
 * - words[i] and puzzles[i] consist of lowercase English letters.
 */

/**
 * words = ["aaaa","asas","able","ability","actt","actor","access"]
 * 相當於 words = ["a", "as", "able", "abilty", "act", "actor", "aces"]
 *
 * 其中先比對 actor
 * 如果符合，那就不需要比對 act, a 了
 */

/**
 * 上面的想法不知道可不可行
 *
 * 現在用以下策略過了
 *   合併 bitmask 是重複的字串
 *   依據 puzzle[0] 直接分類 word bitmask
 *   puzzle 只有 7 個字，所以直接移除有 7 個以上的不同字母的 word
 *
 * TODO: 怎麼還是慢 100ms 秒了
 */

class Solution {
 public:
  vector<int> findNumOfValidWords(vector<string>& words,
                                  vector<string>& puzzles) {
    bool isHead[26];
    for (int i = 0; i < 26; i++) isHead[i] = false;

    int puzzlesSize = puzzles.size();
    int puzzleBitMasks[puzzlesSize];
    for (int i = 0; i < puzzlesSize; i++) {
      string& puzzle = puzzles[i];
      puzzleBitMasks[i] = 0;

      for (int j = 0; j < 7; j++) {
        char& c = puzzle[j];

        if (j == 0) isHead[c - 'a'] = true;
        puzzleBitMasks[i] |= 1 << (c - 'a');
      }

      puzzleBitMasks[i] = ~puzzleBitMasks[i];
    }

    int wordsSize = words.size();
    vector<int> wordBitMasksByHead[26];
    unordered_map<int, int> wordScoreByBitMask;
    for (int i = 0; i < wordsSize; i++) {
      string& word = words[i];
      int bitMask = 0;
      int uniqueAlphabetCount = 0;
      queue<int> uniqueAlphabets;
      bool isValid = true;

      for (char& c : word) {
        int nextBitMask = bitMask | 1 << (c - 'a');
        if (bitMask == nextBitMask) continue;
        bitMask = nextBitMask;
        uniqueAlphabetCount++;
        uniqueAlphabets.push(c - 'a');

        // puzzle 都是 7 個字母
        // word 要是超過 7 個字母一定沒有用
        if (uniqueAlphabetCount <= 7) continue;
        isValid = false;
        break;
      }

      if (!isValid) continue;

      // 如果這個字串出現過
      // 那就加權中分數就好
      if (wordScoreByBitMask.count(bitMask)) {
        wordScoreByBitMask[bitMask]++;
        continue;
      } else {
        wordScoreByBitMask[bitMask] = 1;
      }

      while (!uniqueAlphabets.empty()) {
        wordBitMasksByHead[uniqueAlphabets.front()].push_back(bitMask);
        uniqueAlphabets.pop();
      }
    }

    vector<int> result(puzzlesSize, 0);

    for (int i = 0; i < puzzlesSize; i++) {
      char& c = puzzles[i][0];
      for (int& wordBitMask : wordBitMasksByHead[c - 'a']) {
        if ((wordBitMask & puzzleBitMasks[i]) == 0) {
          result[i] += wordScoreByBitMask[wordBitMask];
        }
      }
    }

    return result;
  }
};