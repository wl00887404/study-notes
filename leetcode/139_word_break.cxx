#include <iostream>
#include <vector>

/**
 * 使用 Trie: 3cabe0d
 * 刪去字典重複組合: q1e16f73
 */

using namespace std;

struct Trie {
  Trie* children[26] = {NULL};
  bool isWord = false;

  Trie() {}
};

int getIndex(string::iterator begin) {
  char c = *begin;
  return c - 'a';
}

void append(string::iterator begin, string::iterator end, Trie* pointer) {
  if (begin == end) {
    pointer->isWord = true;
  } else {
    int index = getIndex(begin);
    if (pointer->children[index] == NULL) pointer->children[index] = new Trie();

    append(begin + 1, end, pointer->children[index]);
  }
}
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    Trie head = Trie();
    for (string& word : wordDict) {
      append(word.begin(), word.end(), &head);
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

    int index = getIndex(begin);
    if (pointer->isWord && wordBreak(begin, end, failPointer, head, head)) {
      return true;
    }
    if (wordBreak(begin + 1, end, failPointer + 1, head,
                  pointer->children[index])) {
      return true;
    }
    if (pointer == head) *failPointer = true;
    return false;
  }
} solution;
