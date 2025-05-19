#include <iostream>
#include <vector>
using namespace std;

/**
 * 2900 來的
 * 與上一題一樣是 subsequence 要一直換 groups
 * 再加上 result[i] 與 result[i + 1] 的 hamming distance 漢明距離差必須為 1
 * 也就是兩個字串只能差一個字元
 *   axy + bxy => TRUE
 *   axy + xya => FALSE
 *
 * 多了這個條件，就有選誰的問題了
 * 2900 要是遇到一群 group = 1，選誰都一樣
 * 但是不同的 word 漢明距離不一樣，可能無法接起來
 */

/**
 * TODO: 每日一題偷抄作業，下次補
 */

class Solution {
 public:
  vector<string>* wordsP;
  vector<string>* groupsP;

  vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                              vector<int>& groups) {}
  void helper() {}
  bool isHammingDistance1(string& s1, string& s2) {
    int size = s1.size();
    if (size != s2.size()) return false;

    bool isDiffFound = false;

    for (int i = 0; i < size; i++) {
      if (s1[i] == s2[i]) continue;
      // 已經找到過了不一樣的字元
      if (isDiffFound) return false;
      // 找到不一樣的字元
      isDiffFound = true;
    }

    // 回傳是否有不一樣的字元
    return isDiffFound;
  }
};