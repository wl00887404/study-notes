#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int sSize = s.size();
    int pSize = p.size();

    if (sSize < pSize) return {};

    int sFrequencies[26];
    int pFrequencies[26];

    for (int i = 0; i < 26; i++) {
      sFrequencies[i] = 0;
      pFrequencies[i] = 0;
    }

    for (int i = 0; i < pSize; i++) {
      sFrequencies[s[i] - 'a']++;
      pFrequencies[p[i] - 'a']++;
    }

    if (valid(sFrequencies, pFrequencies)) {
      result.push_back(0);
    }

    for (int i = 1; i < sSize - pSize + 1; i++) {
      // cout << "移除 " <<s[i - 1]<<" 新增 " <<s[i + pSize]<<endl;
      sFrequencies[s[i - 1] - 'a']--;
      sFrequencies[s[i + pSize - 1] - 'a']++;

      if (valid(sFrequencies, pFrequencies)) {
        result.push_back(i);
      }
    }

    return result;
  }

  bool valid(int* sFrequencies, int* pFrequencies) {
    for (int i = 0; i < 26; i++) {
      if (sFrequencies[i] != pFrequencies[i]) return false;
    }

    return true;
  }
};