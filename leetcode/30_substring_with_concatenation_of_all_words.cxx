#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#include "./log.cxx"
using namespace std;

/**
 * Trie! Finally! 80 ms!
 *
 * TODO: 研究 T1 解
 */

struct TrieNode {
  vector<int> keys;
  TrieNode* children[26] = {NULL};
  bool isWord = false;
  int count = 0;
  int used = 0;

  bool has(char c) { return has(c - 'a'); }
  bool has(int i) { return children[i] != NULL; }

  void resetUsed() {
    used = 0;

    for (int key : keys) children[key]->resetUsed();
  }

  void insert(string& str) {
    string::iterator begin = str.begin();
    string::iterator end = str.end();

    insert(str, begin, end);
  }
  void insert(string& str, string::iterator& begin, string::iterator& end) {
    if (begin == end) {
      isWord = true;
      count++;
    } else {
      int index = *begin - 'a';

      if (!has(index)) {
        keys.push_back(index);
        children[index] = new TrieNode();
      }

      children[index]->insert(str, ++begin, end);
    }
  }

  TrieNode* match(string::iterator& begin, string::iterator& end) {
    int index = *begin - 'a';

    if (begin == end || !has(index)) return NULL;

    TrieNode* nextNode = children[index];

    if (nextNode->isWord) return nextNode;

    return nextNode->match(++begin, end);
  }
};

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int sLength = s.size();
    int wordsLength = words.size();

    if (sLength == 0 || wordsLength == 0) return {};

    int wordLength = words[0].size();

    TrieNode* cache[sLength];
    vector<int> matchIndexies;
    int limit = sLength - wordLength * wordsLength;
    TrieNode* root = new TrieNode();
    vector<int> results;
    string::iterator end = s.end();

    for (string& word : words) root->insert(word);

    bool isSeen[sLength];
    for (int i = 0; i < sLength; i++) isSeen[i] = false;

    bool shouldResetUsed = false;
    for (int i = 0; i <= limit; i++) {
      if (shouldResetUsed) {
        root->resetUsed();
        shouldResetUsed = false;
      }

      int j = 0;
      for (; j < wordsLength; j++) {
        int index = i + wordLength * j;

        if (index >= sLength) break;

        string::iterator begin = s.begin() + index;

        if (!isSeen[index]) {
          isSeen[index] = true;
          cache[index] = root->match(begin, end);
        }

        TrieNode* matched = cache[index];

        if (matched == NULL) break;
        if (++(matched->used) > matched->count) break;

        shouldResetUsed = true;
      }

      if (j == wordsLength) results.push_back(i);
    }

    return results;
  };
} solution;

int main() {
  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};

  // string s = "wordgoodgoodgoodbestword";
  // vector<string> words = {"word", "good", "best", "word"};

  // string s = "wordgoodgoodgoodbestword";
  // vector<string> words = {"word", "good", "best", "good"};

  vector<int> results = solution.findSubstring(s, words);

  log(results);

  return 0;
}