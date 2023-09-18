#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxVowels(string s, int k) {
    int size = s.size();

    int vowelCount = 0;
    for (int i = 0; i < k; i++) {
      if (isVowel(s[i])) vowelCount++;
    }
    // cout << vowelCount << endl;

    // vowelCount 是目前 [i, k) 的母音數
    int i = 0;
    int result = vowelCount;
    while (k < size) {
      // 往後推一格為 [i + 1, k)
      // 少了 s[i] ，多了 s[k]
      if (isVowel(s[i])) vowelCount--;
      if (isVowel(s[k])) vowelCount++;
      // cout << "少了 " << s[i] << " ，";
      // cout << "多了 " << s[k + 1] << " ，";
      // cout << "vowelCount " << vowelCount << endl;
      i++;
      k++;
      result = max(result, vowelCount);
    }

    return result;
  }

  bool isVowel(const char &c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};