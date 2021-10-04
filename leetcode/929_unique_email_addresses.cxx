

#include <iostream>
#include <unordered_map>
#include <vector>

/**
 * 用 Trie 理所當然比 Hash 慢
 * TODO: 學一個 String Hash 吧！
 */

/**
 * 欸所以理論上壓縮後的 Trie 搜尋速度應該更快才對
 */

using namespace std;

class MyTreeNode {
 public:
  bool searchAndInsert(string& s) {
    string::iterator begin = s.begin();
    string::iterator end = s.end();
    bool isLocalName = true;

    return searchAndInsert(begin, end, isLocalName);
  }

 private:
  bool isWord = false;
  unordered_map<char, MyTreeNode*> children;

  bool searchAndInsert(string::iterator& begin, string::iterator& end,
                       bool& isLocalName) {
    if (begin == end) return this->isWord;

    skipDotAndPlusForLocalName(begin, end, isLocalName);

    char& c = *begin;
    bool found = children.count(c);
    if (c == '@') isLocalName = false;

    if (!found) {
      this->insert(begin, end, isLocalName);

      return found;
    } else {
      return this->children[c]->searchAndInsert(++begin, end, isLocalName);
    };
  }

  void skipDotAndPlusForLocalName(string::iterator& begin,
                                  string::iterator& end, bool& isLocalName) {
    if (!isLocalName) return;
    while (*begin == '.') begin++;

    if (*begin != '+') return;

    begin++;
    while (*begin != '@') begin++;
  }

  void insert(string::iterator& begin, string::iterator& end,
              bool& isLocalName) {
    if (begin == end) {
      this->isWord = true;
      return;
    };

    skipDotAndPlusForLocalName(begin, end, isLocalName);

    char& c = *begin;
    if (c == '@') isLocalName = false;

    if (!children.count(c)) children[c] = new MyTreeNode();

    this->children[c]->insert(++begin, end, isLocalName);
  }
};

class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    int result = 0;
    MyTreeNode* dictionary = new MyTreeNode();

    for (string& s : emails) {
      if (!dictionary->searchAndInsert(s)) {
        result++;
      }
    }

    return result;
  }
};