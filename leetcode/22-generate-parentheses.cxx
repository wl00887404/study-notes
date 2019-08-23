#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 未完成

/*
* 1: (1)
* 2: (1, 1)
* 3: (1, 2) (2, 1)
* 4: (1, 3) (2, 2) (3, 1)
* 5: (1, 4) (2, 3) (3, 2) (4, 1)
*/

unordered_map<int, vector<string>> cache = {
    {1, {"()"}}};

class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    if (cache.count(n))
      return cache[n];

    vector<string> parenthesis = generateParenthesis(n - 1);
    vector<string> result;

    // for (string str : parenthesis)
    //   result.push_back("(" + str + ")");

    // for (string str : parenthesis)
    // {
    //   if (!(str[0] == '(' && str[1] == ')'))
    //     result.push_back(str + "()");
    //   result.push_back("()" + str);
    // }

    return result;
  }
} solution;

int main()
{
  vector<string> result = solution.generateParenthesis(1);

  for (string str : result)
    cout << str << endl;
  return 0;
}
