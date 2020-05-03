#include <iostream>

#include "./log.cxx"
using namespace std;

static vector<int> nums = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return vector<int>{};
}();

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int rLength = ransomNote.size();

    if (rLength == 0) return true;

    int mLength = magazine.size();

    if (mLength == 0) return false;

    int frequencies[26] = {0};

    for (int i = 0; i < mLength; i++) frequencies[magazine[i] - 'a']++;

    for (int i = 0; i < rLength; i++) {
      if (--frequencies[ransomNote[i] - 'a'] < 0) return false;
    }

    return true;
  }
} solution;

int main() {
  cout << solution.canConstruct(
              "bg", "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj")
       << endl;

  return 0;
}