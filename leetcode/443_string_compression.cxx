#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int compress(vector<char>& chars) {
    int size = chars.size();
    int i = 0;
    int result = 0;

    while (i < size) {
      int count = 0;
      while ((i + count) < size && chars[i] == chars[i + count]) {
        count++;
      }

      chars[result] = chars[i];
      result++;

      i += count;

      // 如果 count 大於 1，要補數字上去
      if (count != 1) {
        // 升到最高位再開始做
        int numberOfDigits = 1;
        while (numberOfDigits <= count) numberOfDigits *= 10;
        numberOfDigits /= 10;

        while (numberOfDigits != 0) {
          chars[result] = '0' + (count / numberOfDigits);
          count %= numberOfDigits;
          numberOfDigits /= 10;
          result++;
        }
      }
    }

    return result;
  }
};