#include <iostream>
using namespace std;

class Solution
{
public:
  string countAndSay(int n)
  {
    if (n == 1)
      return "1";

    string last_result = countAndSay(n - 1) + "$";
    string result = "";

    int count = 0;
    for (int i = 0; i < last_result.length() - 1; i++)
    {
      char c = last_result[i];
      count++;

      if (c != last_result[i + 1])
      {
        result += count + '0';
        result += c;
        count = 0;
      }
    }

    return result;
  }
} solution;