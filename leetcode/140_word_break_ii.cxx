#include <iostream>
#include <vector>

using namespace std;

/**
 * 把每個 index 匹配 dict 的情況組合在一起
 * 是 0ms 了
 * 感覺也沒有什麼別可以優化的地方
 *
 * 明明是 hard 卻可以直接寫得出來
 * 感覺有點空虛
 */

class TrieNode {
 public:
  TrieNode* children[26];
  int wordIndex = -1;

  TrieNode() {
    for (int i = 0; i < 26; i++) {
      children[i] = NULL;
    }
  }

  void insert(string::iterator& begin, string::iterator& end, int& wordIndex) {
    if (begin == end) {
      this->wordIndex = wordIndex;
      return;
    }

    char& c = *begin++;
    if (children[c - 'a'] == NULL) {
      children[c - 'a'] = new TrieNode();
    }

    children[c - 'a']->insert(begin, end, wordIndex);
  }
};

class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    sSize = s.size();
    sPointer = &s;
    wordDictPointer = &wordDict;
    int dictSize = wordDict.size();
    wordIndexes.resize(sSize);
    isExecuted.resize(sSize, false);

    // 把所有 dict 加進 trie
    for (int i = 0; i < dictSize; i++) {
      string& word = wordDict[i];
      string::iterator begin = word.begin();
      string::iterator end = word.end();
      trie->insert(begin, end, i);
    }

    // 拼湊每一種組合
    string initS = "";
    helper(0, initS);

    return result;
  }

  void helper(int i, string& s) {
    if (i >= sSize) return;

    calcWordIndexesIfNeed(i);
    vector<string>& wordDict = *wordDictPointer;

    for (int& wordIndex : wordIndexes[i]) {
      string& word = wordDict[wordIndex];

      if (word.size() + i == sSize) {
        result.push_back(s + word);
      } else {
        string nextS = s + word + " ";
        helper(word.size() + i, nextS);
      }
    }
  }

  TrieNode* trie = new TrieNode();
  vector<string>* wordDictPointer;
  string* sPointer;
  int sSize;
  vector<string> result;
  vector<vector<int>> wordIndexes;
  vector<bool> isExecuted;

  void calcWordIndexesIfNeed(int i) {
    if (isExecuted[i]) return;

    int j = i;
    TrieNode* pointer = trie;
    string& s = *sPointer;

    while (j < sSize) {
      pointer = pointer->children[s[j++] - 'a'];
      if (pointer == NULL) break;
      if (pointer->wordIndex == -1) continue;
      wordIndexes[i].push_back(pointer->wordIndex);
    }

    isExecuted[i] = true;
  }
};