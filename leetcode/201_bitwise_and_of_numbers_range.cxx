#include <iostream>
#include <stack>
using namespace std;

/**
 * 如果範圍介於 8 (1000) ~ 15 (1111)
 * 那結果為 8 (1000)
 *
 * 如果範圍介於 12 (1100) ~ 15 (1111)
 * 那結果為 12 (1100)
 *
 * 如果範圍介於 10 (1010) ~ 15 (1111)
 * 那結果為 8 (1000)
 *
 * 所以是最左側至少能夠產生幾個 1 連續嗎？
 */

/**
 * 而且兩個 1 開始的位置要一樣
 */

class StackSolution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    if (left == right) return left;

    stack<bool> stack1;
    stack<bool> stack2;

    while (left) {
      stack1.push(left & 1);
      left >>= 1;
    }

    while (right) {
      stack2.push(right & 1);
      right >>= 1;
    }

    if (stack1.size() != stack2.size()) return 0;

    int result = 0;
    bool metZero = false;

    while (!stack1.empty() && !stack2.empty()) {
      if (stack1.top() != stack2.top()) {
        metZero = true;
      }

      result <<= 1;

      if (!metZero) result |= stack1.top();

      stack1.pop();
      stack2.pop();
    }

    return result;
  }
} solution2;

class Solution {
 public:
  int rangeBitwiseAnd(int left, int right) {
    if (left == right) return left;
    int i = left;
    int leftBits = 0;
    int reverseLeft = 0;

    while (i) {
      leftBits++;
      reverseLeft <<= 1;
      reverseLeft |= i & 1;
      i >>= 1;
    }

    int j = right;
    int rightBits = 0;
    int reverseRight = 0;

    while (j) {
      rightBits++;
      reverseRight <<= 1;
      reverseRight |= j & 1;
      j >>= 1;
    }

    if (leftBits != rightBits) return 0;

    int result = 0;
    bool metZero = false;

    while (leftBits != 0 && rightBits != 0) {
      if ((reverseLeft & 1) != (reverseRight & 1)) {
        metZero = true;
      }

      result <<= 1;

      if (!metZero) result |= reverseLeft & 1;

      leftBits--;
      rightBits--;
      reverseLeft >>= 1;
      reverseRight >>= 1;
    }

    return result;
  }
} solution;

int main() {
  cout << solution.rangeBitwiseAnd(5, 7) << endl;
  // cout << solution.rangeBitwiseAnd(10, 11) << endl;
  // cout << solution.rangeBitwiseAnd(1, 2147483647) << endl;
  // cout << solution.rangeBitwiseAnd(1, 2147483647) << endl;
  return 0;
}
