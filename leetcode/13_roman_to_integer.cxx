#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int romanToInt(string s)
  {
    const char *pointer = s.c_str();
    int result = 0;

    unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    while (*pointer != '\0')
    {
      if (*pointer == 'C' && *(pointer + 1) == 'M')
      {
        result += 900;
        pointer += 2;
        continue;
      }

      if (*pointer == 'C' && *(pointer + 1) == 'D')
      {
        result += 400;
        pointer += 2;
        continue;
      }

      if (*pointer == 'X' && *(pointer + 1) == 'C')
      {
        result += 90;
        pointer += 2;
        continue;
      }

      if (*pointer == 'X' && *(pointer + 1) == 'L')
      {
        result += 40;
        pointer += 2;
        continue;
      }

      if (*pointer == 'I' && *(pointer + 1) == 'X')
      {
        result += 9;
        pointer += 2;
        continue;
      }

      if (*pointer == 'I' && *(pointer + 1) == 'V')
      {
        result += 4;
        pointer += 2;
        continue;
      }

      result += map[*pointer];
      pointer++;
    }

    return result;
  }
};
