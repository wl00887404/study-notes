#include <iostream>
using namespace std;

/**
 * TODO: 老實說，我不知道這題的解法到底在幹麻
 *   https://skyyen999.gitbooks.io/-leetcode-with-javascript/content/questions/371md.html
 */

class Solution {
 public:
  int getSum(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    while (b != 0) {
      int carry = a & b;  //進位值

      a = a ^ b;  //相加

      b = carry << 1;  //進位
    }

    return a;
  }
} solution;

int main() {
  cout << solution.getSum(2, 3) << endl;
  return 0;
}