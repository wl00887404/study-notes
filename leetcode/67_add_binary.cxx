#include <iostream>

using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) { return helper(a, b); }

  string helper(string& a, string& b) {
    if (a.size() < b.size()) return helper(b, a);

    int aLast = a.size() - 1;
    int bLast = b.size() - 1;
    string result = "";
    char carry = '0';

    while (aLast >= 0 && bLast >= 0) {
      if (a[aLast] == b[bLast]) {
        result = carry + result;
        carry = a[aLast] == '1' ? '1' : '0';
      } else {
        result = (carry == '0' ? '1' : '0') + result;
        // carry 0 + 1 會是 01 ， carry 仍然是 0
        // carry 1 + 1 會是 10 ， carry 仍然是 1
      }
      aLast--;
      bLast--;
    }

    while (aLast >= 0) {
      if (a[aLast] == '1' && carry == '1') {
        result = '0' + result;

      } else if (a[aLast] == '0') {
        result = carry + result;
        carry = '0';
      } else {
        result = '1' + result;
      }

      aLast--;
    }

    if (carry == '1') {
      result = '1' + result;
    }

    return result;
  }
};