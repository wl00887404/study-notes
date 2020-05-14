#include <iostream>
using namespace std;

class Trie {
 public:
  Trie() {}

  void insert(string word) {
    string::iterator begin = word.begin();
    string::iterator end = word.end();
    insert(begin, end);
  }

  bool search(string word) {
    string::iterator begin = word.begin();
    string::iterator end = word.end();

    return search(begin, end);
  }

  bool startsWith(string prefix) {
    string::iterator begin = prefix.begin();
    string::iterator end = prefix.end();

    return startsWith(begin, end);
  }

 private:
  Trie* children[26] = {NULL};
  bool isWord = false;

  void insert(string::iterator& begin, string::iterator& end) {
    if (begin == end) {
      isWord = true;
      return;
    }

    int i = *begin - 'a';

    if (children[i] == NULL) children[i] = new Trie();

    children[i]->insert((++begin), end);
  }

  bool search(string::iterator& begin, string::iterator& end) {
    if (begin == end) return isWord;

    int i = *begin - 'a';

    if (children[i] == NULL) return false;

    return children[i]->search((++begin), end);
  }

  bool startsWith(string::iterator& begin, string::iterator& end) {
    if (begin == end) return true;

    int i = *begin - 'a';

    if (children[i] == NULL) return false;

    return children[i]->startsWith((++begin), end);
  }
};

int main() {
  Trie* trie = new Trie();

  trie->insert("apple");
  cout << trie->search("apple") << endl;    // true
  cout << trie->search("app") << endl;      // false
  cout << trie->startsWith("app") << endl;  // true
  trie->insert("app");
  cout << trie->search("app") << endl;  // true

  return 0;
}