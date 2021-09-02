#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    int size1 = num1.size();
    int size2 = num2.size();
    if (size1 < size2) return addStrings(num2, num1);

    int i = 0;
    int last1 = size1 - 1;
    int last2 = size2 - 1;
    int carry = 0;
    char result[size1 + 2];

    while (last2 >= 0) {
      int value = (num1[last1] - '0') + (num2[last2] - '0') + carry;
      carry = value / 10;
      result[i] = value % 10 + '0';
      last1--;
      last2--;
      i++;
    }

    while (last1 >= 0) {
      int value = (num1[last1] - '0') + carry;
      carry = value / 10;
      result[i] = value % 10 + '0';
      last1--;
      i++;
    }

    result[i] = carry + '0';
    if (carry == 0) i--;

    reverse(&result[0], &result[i + 1]);
    result[i + 1] = '\0';

    return string(result);
  }
};