#include <iostream>
#include <vector>
using namespace std;

/**
 * Trie 解超時 QAQ
 */

struct Trie {
  Trie* children[26] = {NULL};
  bool isWord = false;
  bool isReachable = false;

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

bool find(string::iterator begin, string::iterator end, Trie* head,
          Trie* pointer) {
  if (pointer == NULL) return false;
  pointer->isReachable = true;

  if (begin == end) return pointer->isWord;

  if (pointer->isWord && find(begin, end, head, head)) return true;

  int index = getIndex(begin);
  return find(begin + 1, end, head, pointer->children[index]);
}

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    Trie head = Trie();
    for (string& word : wordDict) {
      append(word.begin(), word.end(), &head);
    }

    for (string& word : wordDict) {
      find(word.begin(), word.end(), &head, &head);
    }

    return wordBreak(s.begin(), s.end(), &head, &head);
  }
  bool wordBreak(string::iterator begin, string::iterator end, Trie* head,
                 Trie* pointer) {
    if (pointer == NULL) return false;
    if (!pointer->isReachable) return false;
    if (begin == end) return pointer->isWord;

    int index = getIndex(begin);
    if (pointer->isWord && wordBreak(begin, end, head, head)) return true;

    return wordBreak(begin + 1, end, head, pointer->children[index]);
  }
} solution;

int main() {
  string s =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaa";
  vector<string> wordDict = {"aa",         "aaa",     "aaaa",     "aaaaa",
                             "aaaaaa",     "aaaaaaa", "aaaaaaaa", "aaaaaaaaa",
                             "aaaaaaaaaa", "ba"};

  cout << solution.wordBreak(s, wordDict) << endl;
  return 0;
}
