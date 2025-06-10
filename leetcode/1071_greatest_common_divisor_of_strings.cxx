#include <iostream>
using namespace std;

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    int size1 = str1.size();
    int size2 = str2.size();

    int gcd = calcGcd(size1, size2);

    for (int i = gcd; i >= 1; i--) {
      if (gcd % i != 0) continue;
      if (!match(str1, str2, i, i)) continue;
      if (!match(str1, str1, size1, i)) continue;
      if (!match(str2, str2, size2, i)) continue;

      return str1.substr(0, i);
    }

    return "";
  }

  int calcGcd(int a, int b) {
    while (a != 0 && b != 0) {
      a %= b;
      if (a != 0) b %= a;
    }

    return a + b;
  }

  bool match(string& str1, string& str2, int& size1, int& size2) {
    for (int i = 0; i < size1; i++) {
      if (str1[i] != str2[i % size2]) {
        return false;
      }
    }

    return true;
  }
};