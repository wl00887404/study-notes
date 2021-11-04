#include <iostream>
using namespace std;

class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int length1 = num1.size();
    int length2 = num2.size();

    if (length1 > length2) return multiply(num2, num1);

    int length = num1.size() + num2.size();
    int carry = 0;
    char cs[length + 1];

    cs[length] = '\0';

    for (int i = 0; i < length - 1; i++) {
      int product = 0;

      for (int j = 0; j < length1; j++) {
        int k = i - j;

        if (k < 0 || k >= length2) continue;

        product +=
            (num1[length1 - j - 1] - '0') * (num2[length2 - k - 1] - '0');
      }

      carry += product;
      cs[length - i - 1] = carry % 10 + '0';
      carry /= 10;
    }

    if (carry == 0) return string(cs + 1);

    cs[0] = carry % 10 + '0';

    return string(cs);
  }
} solution;

int main() {
  cout << solution.multiply("37", "2") << endl;

  return 0;
}