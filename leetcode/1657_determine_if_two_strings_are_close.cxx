#include <iostream>
#include <vector>

using namespace std;

/**
 * 只能交換字元，或是把某個字元全部轉換成另一個已經出現的字元
 * 操作一交換字元比較不重要，就是調換順序，重點是操作二可以改變組成
 * 只要兩個字串組成次數是一樣的，就可以轉過去
 */

class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    vector<int> frequency1(26, 0);
    vector<int> frequency2(26, 0);

    for (const char& c1 : word1) {
      frequency1[c1 - 'a']++;
    }

    for (const char& c2 : word2) {
      frequency2[c2 - 'a']++;
    }

    // 確定 word1 有的字元 word2 都有
    for (int i = 0; i < 26; i++) {
      if (frequency1[i] == 0 && frequency2[i] != 0) return false;
      if (frequency1[i] != 0 && frequency2[i] == 0) return false;
    }

    sort(frequency1.begin(), frequency1.end());
    sort(frequency2.begin(), frequency2.end());

    for (int i = 0; i < 26; i++) {
      if (frequency1[i] != frequency2[i]) return false;
    }

    return true;
  }
};