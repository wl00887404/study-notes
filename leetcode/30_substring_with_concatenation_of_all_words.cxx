#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

#include "./log.cxx"
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  string* refer = NULL;
  int count = 0;
  int used = 0;
  bool has(char c) { return children.count(c); }
  void resetUsed() {
    used = 0;
    for (auto p : children) p.second->resetUsed();
  }
};

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int sLength = s.size();
    int wordsLength = words.size();

    if (sLength == 0 || wordsLength == 0) return {};

    int wordLength = words[0].size();

    unordered_map<int, TrieNode*> matchMap;
    vector<int> matchIndexies;
    int limit = sLength - wordLength * wordsLength;
    TrieNode* root = new TrieNode();

    for (string& word : words) {
      TrieNode* p = root;

      for (int i = 0; i < wordLength; i++) {
        if (!p->has(word[i])) p->children[word[i]] = new TrieNode();

        p = p->children[word[i]];
      }

      if (p->refer == NULL) p->refer = &word;
      p->count++;
    }

    for (int i = 0; i < sLength; i++) {
      TrieNode* p = root;
      int j = 0;

      while (true) {
        if (p->refer != NULL) {
          matchMap[i] = p;
          if (i <= limit) matchIndexies.push_back(i);
          break;
        }

        if (!p->has(s[i + j])) break;

        p = p->children[s[i + j]];
        j++;
      }
    }

    vector<int> results;

    for (int& begin : matchIndexies) {
      root->resetUsed();

      int i = 0;
      for (; i < wordsLength; i++) {
        int index = begin + wordLength * i;

        if (!matchMap.count(index)) break;
        if (index >= sLength) break;

        matchMap[index]->used++;

        if (matchMap[index]->used > matchMap[index]->count) break;
      }

      if (i == wordsLength) results.push_back(begin);
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