#include <iostream>
#include <vector>
using namespace std;

int abs(int x)
{
  return x < 0 ? x * -1 : x;
}

int min(int x, int y)
{
  return x < y ? x : y;
}

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int result = 0;

    for (int i = 0; i < height.size(); i++)
    {
      for (int j = i + 1; j < height.size(); j++)
      {
        int volume = abs(i - j) * min(height[i], height[j]);
        if (volume > result)
        {
          result = volume;
        }
      }
    }

    return result;
  }
};