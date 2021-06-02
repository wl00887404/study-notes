#include <iostream>
using namespace std;

/**
 * 同 208 是 Trie 的基本題
 */

class WordDictionary {
 public:
  WordDictionary() {
    for (int i = 0; i < 26; i++) {
      this->children[i] = NULL;
    }
  }

  void addWord(string word) {
    string::iterator begin = word.begin();
    string::iterator end = word.end();

    addWord(begin, end);
  }

  void addWord(string::iterator begin, string::iterator end) {
    if (begin == end) {
      this->isWord = true;
      return;
    }

    int i = *begin - 'a';
    if (this->children[i] == NULL) this->children[i] = new WordDictionary();

    this->children[i]->addWord(++begin, end);
  }

  bool search(string word) {
    string::iterator begin = word.begin();
    string::iterator end = word.end();

    return search(begin, end);
  }
  bool search(string::iterator begin, string::iterator end) {
    if (begin == end) return this->isWord;

    if (*begin != '.') {
      int i = *begin - 'a';
      if (this->children[i] == NULL) return false;

      return this->children[i]->search(++begin, end);
    }

    begin++;
    for (int i = 0; i < 26; i++) {
      if (this->children[i] == NULL) continue;

      if (this->children[i]->search(begin, end)) return true;
    }

    return false;
  }

 private:
  WordDictionary* children[26];
  bool isWord = false;
};
