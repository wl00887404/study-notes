#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
 public:
  string* word = NULL;
  TrieNode* children[26];

  TrieNode() {
    for (int i = 0; i < 26; i++) children[i] = NULL;
  }

  bool isWord() { return word != NULL; }

  void insert(string& word) {
    string::iterator begin = word.begin();
    string::iterator end = word.end();

    insert(word, begin, end);
  }

  void erase() {
    // 如果還有 children 那就取消自己的 word 就好
    if (length != 0) {
      word = NULL;
      return;
    }

    // 沒有 children 了
    // 移除自己的節點
    if (!parent) return;

    *link = NULL;  // 斷掉與 parent 的連結
    parent->length--;
    if (parent->length == 0) parent->erase();
  }

 private:
  int length = 0;
  TrieNode** link = NULL;
  TrieNode* parent = NULL;

  void insert(string& word, string::iterator& begin, string::iterator& end) {
    if (begin == end) {
      this->word = &word;
      return;
    }

    int index = *begin - 'a';
    if (children[index] == NULL) {
      children[index] = new TrieNode();
      children[index]->link = &children[index];
      children[index]->parent = this;
      length++;
    };

    children[index]->insert(word, ++begin, end);
  }
};

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    this->board = board;
    mLength = board.size();
    nLength = board[0].size();

    vector<string> result;
    TrieNode* trie = new TrieNode();
    for (string& word : words) trie->insert(word);

    for (int m = 0; m < mLength; m++) {
      for (int n = 0; n < nLength; n++) {
        helper(trie, m, n, result);
      }
    }

    return result;
  }

 private:
  vector<vector<char>> board;
  int mLength;
  int nLength;

  void helper(TrieNode* trie, int m, int n, vector<string>& result) {
    if (m < 0 || m == mLength) return;
    if (n < 0 || n == nLength) return;

    char c = board[m][n];
    if (c == '\0') return;

    trie = trie->children[c - 'a'];
    if (trie == NULL) return;

    board[m][n] = '\0';

    if (trie->isWord()) {
      result.push_back(*trie->word);
      trie->erase();
    }

    helper(trie, m - 1, n, result);
    helper(trie, m, n + 1, result);
    helper(trie, m + 1, n, result);
    helper(trie, m, n - 1, result);

    board[m][n] = c;
  }

} solution;
