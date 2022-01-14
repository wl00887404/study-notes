#include <iostream>
#include <vector>

using namespace std;

/**
 * 初看覺得超 hard 耶
 * 全部跑過一定是 3 ^ n
 */

/**
 * 提示 3 說：
 *   我們可以追蹤每一個字串以在最後時進行運算，
 *   但這些操作相當耗時
 *   設想我們可以一邊迭代一邊計算嗎？
 *
 * 依據寫計算機的經驗
 * 現在是 *
 *   遇到 * 累積乘，前方的 + - 繼續累積
 *   遇到 + - 直接把累積都處理掉
 *
 * 如果要使用前面運算的結果
 * 想要快 stack 就要保留
 * 不然會一直複製 stack
 */

/**
 * 2021/9/19 00:23:07
 * 想了一天無法下手，
 * 我看，這課還是得逃的。
 */

/**
 * 2021/11/11
 * 欸不對
 * 不一定是要塞 operators 在中間
 * 是可以不塞的
 *
 * num = "911", target = 2
 * 結果可以是 "91+1"
 */

/**
 * 假設 "1234"
 * 4 => + 4 = 4
 *   => - 4 = -4
 *
 * 3 => + 3 + 4 有了
 *      - 3 + 4 有了
 *      + 3 - 4 等於 3 + (-4) 所以有了
 *      - 3 - 4 等於 -3 + (-4) 所以有了
 *      + 3 * 4 = 12
 *      - 3 * 4 = -12
 *      + 3   4 = 34
 *      - 3   4 = -34
 *
 * 2 => + 2 + ... 有了 * 4
 *      - 2 + ... 有了 * 4
 *      + 2 - ... 有了 * 4
 *      - 2 - ... 有了 * 4
 *      + 2 * 3 + 4 = 6 + 4 = 10
 *      + 2 * 3 - 4 = 6 + (-4) = 2
 *      - 2 * 3 + 4 = -6 + 4 = -2
 *      - 2 * 3 - 4 = -6 - 4 = -10
 *      + 2 * 3 * 4 = 2 * (+ 3 * 4) = 2 * 12 = 24
 *      - 2 * 3 * 4 = - 2 * (+ 3 * 4) = -2 * 12 = -24
 *      + 2   3 + 4 = 23 + 4 = 27
 *      + 2   3 - 4 = 23 + (-4) = 19
 *      - 2   3 + 4 = -23 + 4 = -19
 *      - 2   3 - 4 = -23 + (-4) = -27
 *      + 2   3   4 = 234
 *      - 2   3   4 = -234
 * 1 => 1 + ... 有了
 *      1 - ... 有了
 *      1 * 2 + ... 有了
 *      1 * 2 * 3 + ... 有了
 *      1   2 + ... 有了
 *      1   2   3 + ... 有了
 *
 */

/**
 * 2021/11/17
 * 水啦寫出來了
 * 就是上一個 comment 那樣
 */

/**
 * TODO: 參考 494 改一下 cache 的形式
 * 以及那個 getProductExpressions 長得有點醜也可以改一下
 */
struct getProductExpressions {
  vector<pair<string, int>>* result;
  int numSize;
  string* num;

  getProductExpressions(string& num, int i, vector<pair<string, int>>& result) {
    this->num = &num;
    numSize = num.size();
    this->result = &result;

    helper(i, "", 0);
  }

  void helper(int i, string expression, int size) {
    if (size != 0) result->push_back({expression, i});
    if (i == numSize) return;

    string s = string(1, (*num)[i]);

    if (size == 0) return helper(i + 1, s, 1);

    helper(i + 1, expression + "*" + s, size + 2);

    /**
     * 0 開頭
     * 或是 0 前面是 *
     */
    if (expression[size - 1] == '0' &&
        (size == 1 || expression[size - 2] == '*')) {
      return;
    }

    helper(i + 1, expression + s, size + 1);
  }
};

class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    int size = num.size();

    vector<pair<string, long long>> cache[size];

    int i = size - 1;
    for (int i = size - 1; 0 < i; i--) {
      vector<pair<string, int>> productExpressions;
      getProductExpressions(num, i, productExpressions);

      for (pair<string, int>& productExpression : productExpressions) {
        string& expression = productExpression.first;
        long long value = calcProductExpression(expression);
        int cacheIndex = productExpression.second;

        if (cacheIndex >= size) {
          // 後面不需要 +- 東西
          cache[i].push_back({"+" + expression, value});
          cache[i].push_back({"-" + expression, -1 * value});
        } else {
          // 幹不知道取什麼名子啦
          for (pair<string, long long>& foo : cache[cacheIndex]) {
            cache[i].push_back(
                {"+" + expression + foo.first, value + foo.second});
            cache[i].push_back(
                {"-" + expression + foo.first, -1 * value + foo.second});
          }
        }
      }
    }

    vector<string> result;
    vector<pair<string, int>> productExpressions;
    getProductExpressions(num, 0, productExpressions);

    for (pair<string, int>& productExpression : productExpressions) {
      string& expression = productExpression.first;
      long long value = calcProductExpression(expression);
      int cacheIndex = productExpression.second;

      if (cacheIndex >= size) {
        if (value == target) result.push_back(expression);
      } else {
        for (pair<string, long long>& foo : cache[cacheIndex]) {
          if ((value + foo.second) != target) continue;

          result.push_back(expression + foo.first);
        }
      }
    }

    return result;
  }

  long long calcProductExpression(string& expression) {
    long long result = 1;
    long long value = 0;

    for (char& c : expression) {
      if (c == '*') {
        result *= value;
        value = 0;
      } else {
        value = 10 * value + (c - '0');
      }
    }

    return result * value;
  }
} solution;

int main() {
  // vector<string> result = solution.addOperators("123456789", 45);
  vector<string> result = solution.addOperators("2147483648", -2147483648);

  cout << result.size() << endl;
  for (string& s : result) {
    cout << s << endl;
  }

  // 測試 getProductExpressions
  // vector<pair<string, int>> result;
  // string num = "1234";
  // getProductExpressions(num, 2, result);

  // for (pair<string, int>& pair : result) {
  //   cout << pair.first << ": " << pair.second << endl;
  // }

  return 0;
}
