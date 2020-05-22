#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  string frequencySort(string s) {
    unordered_map<char, int> frequencies;

    for (char c : s) frequencies[c]++;

    map<int, vector<char>> groups;

    for (pair<char, int> p : frequencies) groups[p.second].push_back(p.first);

    int length = s.length();
    char cs[length + 1];
    cs[length] = '\0';
    int i = length - 1;

    for (pair<int, vector<char>> p : groups) {
      for (char c : p.second) {
        int time = p.first;

        while (time--) {
          cs[i] = c;
          i--;
        }
      }
    }

    return string(cs);
  }
} solution;

int main() {
  cout << solution.frequencySort("tree") << endl;
  return 0;
}