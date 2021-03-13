#include <iostream>
#include <vector>

/**
 * 使用 Trie: 3cabe0d
 * 刪去字典重複組合: q1e16f73
 */

using namespace std;

class Trie {
 private:
  static int getIndex(char& c) { return c - 'a'; }

 public:
  Trie* children[26] = {NULL};
  bool isWord = false;

  void append(string s) { this->append(s.begin(), s.end()); }
  void append(string::iterator begin, string::iterator end) {
    if (begin == end) {
      this->isWord = true;
    } else {
      int index = getIndex(*begin);
      if (this->children[index] == NULL) this->children[index] = new Trie();

      this->children[index]->append(begin + 1, end);
    }
  }

  Trie* getChild(char& c) {
    int index = c - 'a';
    return this->children[index];
  }
};

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    Trie head = Trie();
    for (string& word : wordDict) {
      head.append(word.begin(), word.end());
    }

    int length = s.length();
    bool failureArray[length];
    for (int i = 0; i < length; i++) failureArray[i] = false;

    return wordBreak(s.begin(), s.end(), failureArray, &head, &head);
  }

  bool wordBreak(string::iterator begin, string::iterator end,
                 bool* failPointer, Trie* head, Trie* pointer) {
    if (pointer == NULL) return false;
    if (pointer == head && *failPointer == true) return false;
    if (begin == end) return pointer->isWord;

    if (pointer->isWord && wordBreak(begin, end, failPointer, head, head)) {
      return true;
    }
    if (wordBreak(begin + 1, end, failPointer + 1, head,
                  pointer->getChild(*begin))) {
      return true;
    }

    if (pointer == head) *failPointer = true;
    return false;
  }
} solution;
