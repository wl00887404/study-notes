#include <iostream>
#include <stack>

using namespace std;

/**
 * 完成後需要 12ms 耶
 * 感覺的在 push pop stack 花了太多時間
 * 
 * 如果是 + - 連續
 * 或是 * / 連續
 * 其實不需要 stack 也可算出答案
 * 
 * 
 * 主要是像是這種情境
 * 1 + 2 *
 * 1 + 3 *
 * 
 * 要先進入 * / 模式
 * 再回歸 + - 模式
 * 
 * 
 */

class Solution {
 public:
  int calculate(string s) {
    int size = s.size();
    stack<int> numbers;
    stack<char> operators;

    for (int i = 0; i < size; i++) {
      if (s[i] == ' ') continue;

      if (s[i] == '+' || s[i] == '-') {
        calc(numbers, operators, true);
        operators.push(s[i]);
      } else if (s[i] == '*' || s[i] == '/') {
        calc(numbers, operators, false);

        operators.push(s[i]);
      } else {
        //數字們
        int number = 0;
        while (i < size && '0' <= s[i] && s[i] <= '9') {
          number = 10 * number + (s[i] - '0');
          i++;
        }
        i--;
        numbers.push(number);
      }
    }

    calc(numbers, operators, true);

    return numbers.top();
  }

  void calc(stack<int>& numbers, stack<char>& operators, bool withPlusMinus) {
    while (!operators.empty()) {
      if (!withPlusMinus &&
          (operators.top() == '+' || operators.top() == '-')) {
        break;
      }

      int number2 = numbers.top();
      numbers.pop();
      int number1 = numbers.top();
      numbers.pop();

      switch (operators.top()) {
        case '+':
          number1 += number2;
          break;
        case '-':
          number1 -= number2;
          break;
        case '*':
          number1 *= number2;
          break;
        case '/':
          number1 /= number2;
          break;
        default:
          break;
      }

      operators.pop();
      numbers.push(number1);
    }
  }
};