#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> result;

    for (int i = 0; i < words.size(); i++) {
      if (includes(words[i], x)) {
        result.push_back(i);
      }
    }

    return result;
  }

  bool includes(string& s, char& x) {
    for (const char& c : s) {
      if (x == c) return true;
    }

    return false;
  }
};