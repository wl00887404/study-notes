#include <iostream>
#include <vector>
using namespace std;

/**
 * Trie 解超時 QAQ
 */

struct Trie {
  Trie* children[26] = {NULL};
  bool isWord = false;

  Trie() {}
};

int getIndex(string::iterator begin) {
  char c = *begin;
  return c - 'a';
}

bool append(string::iterator begin, string::iterator end, Trie* head) {
  if (begin == end) return (head->isWord = true);

  int index = getIndex(begin);
  if (head->children[index] == NULL) head->children[index] = new Trie();

  return append(begin + 1, end, head->children[index]);
}

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    Trie head = Trie();
    for (string& word : wordDict) {
      append(word.begin(), word.end(), &head);
    }

    return wordBreak(s.begin(), s.end(), &head, &head);
  }
  bool wordBreak(string::iterator begin, string::iterator end, Trie* head,
                 Trie* pointer) {
    if (pointer == NULL) return false;
    if (begin == end) return pointer->isWord;

    int index = getIndex(begin);
    if (pointer->isWord && wordBreak(begin, end, head, head)) return true;

    return wordBreak(begin + 1, end, head, pointer->children[index]);
  }
} solution;

// int main() {
//   string s = "leetcode";
//   vector<string> wordDict = {"leet", "code"};
//   cout << solution.wordBreak(s, wordDict) << endl;
//
//   return 0;
// }
