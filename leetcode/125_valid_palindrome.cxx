#include <iostream>
using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    string::iterator begin = s.begin();
    string::iterator end = s.end() - 1;

    while (true) {
      int charCode1;
      int charCode2;
      while ((charCode1 = getCharCode(begin)) == -1 && begin != end) begin++;
      while ((charCode2 = getCharCode(end)) == -1 && begin != end) end--;

      if (begin == end) return true;
      if (begin + 1 == end && charCode1 == charCode2) return true;
      if (charCode1 != charCode2) break;

      begin++;
      end--;
    }

    return false;
  }

 private:
  int getCharCode(string::iterator it) {
    int charCode = *it;
    // 數字
    if (48 <= charCode && charCode <= 57) return charCode;
    // 小寫字母
    if (97 <= charCode && charCode <= 122) return charCode;
    // 大寫轉小寫
    if (65 <= charCode && charCode <= 90) return charCode - 'A' + 'a';
    // 其他字母
    return -1;
  }
} solution;

int main() {
  cout << (int)'9' << endl;
  cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;

  return 0;
}