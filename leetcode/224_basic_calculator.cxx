#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
 * 老 stack 方法怎麼樣
 * 遇到數字直接輸出
 *
 * a + b * c +
 * stack: + *
 * income: +
 * 表示 b * c 可以做了
 *
 * a - b / (c - d * e + f)
 * stack: - / ( - *
 *
 *
 */

/**
 * Basic Calculator II 有了乘除
 * 難度卻是 Medium 耶
 * Whyyy
 */

/**
 * 運算子沒有優先序
 * 感覺是不用這麼麻煩
 */

class Solution {
 public:
  int calculate(string s) {
    string::iterator pointer = s.begin();
    string::iterator end = s.end();
    stack<int> numbers;
    stack<char> operators;

    while (pointer != end) {
      char& c = *pointer;
      if (isDigtal(c)) {
        numbers.push(readInt(pointer, end));
        continue;
      }

      pointer++;

      if (c == ' ') continue;

      if (c != '(') calculate(numbers, operators);

      if (c == ')') {
        operators.pop();  // 移除左括號
      } else {
        operators.push(c);
      }
    }

    calculate(numbers, operators);

    return numbers.top();
  }

  void calculate(stack<int>& numbers, stack<char>& operators) {
    while (!operators.empty() && operators.top() != '(') {
      int num2 = numbers.top();
      numbers.pop();

      int num1 = !numbers.empty() ? numbers.top() : 0;
      if (!numbers.empty()) numbers.pop();

      char& op = operators.top();
      operators.pop();

      if (op == '+') {
        numbers.push(num1 + num2);
      } else {
        numbers.push(num1 - num2);
      }
    }
  }

  bool isDigtal(char& c) { return '0' <= c && c <= '9'; }

  int readInt(string::iterator& pointer, string::iterator& end) {
    int result = 0;

    while (pointer != end) {
      char& c = *pointer;
      if (!isDigtal(c)) break;

      result = result * 10 + (c - '0');
      pointer++;
    }

    return result;
  }
} solution;

int main() {
  // string s = " 2-1 + 2 ";
  // string s = "2147483647";
  // string s = "-2+ 1";
  string s = "7 + (5)";
  cout << solution.calculate(s) << endl;

  return 0;
}