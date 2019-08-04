#include <iostream>
using namespace std;

struct Entity
{
  string key;
  int value;
  Entity(string key, int value) : key(key), value(value) {}
};

class Solution
{
public:
  string intToRoman(int num)
  {
    string result = "";
    Entity entities[] = {
        Entity("M", 1000),
        Entity("CM", 900),
        Entity("D", 500),
        Entity("CD", 400),
        Entity("C", 100),
        Entity("XC", 90),
        Entity("L", 50),
        Entity("XL", 40),
        Entity("X", 10),
        Entity("IX", 9),
        Entity("V", 5),
        Entity("IV", 4),
        Entity("I", 1),
    };

    while (num != 0)
    {
      for (int i = 0; i < 13; i++)
      {
        Entity entity = entities[i];

        if (num >= entity.value)
        {
          num -= entity.value;
          result += entity.key;
          break;
        }
      }
    }

    return result;
  }
} solution;

int main()
{
  cout << solution.intToRoman(3) << endl;

  return 0;
}