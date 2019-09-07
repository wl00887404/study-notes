#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<char> s;

bool isJiugonggeValid(int x, int y, vector<vector<char>> &board)
{
  if (!s.empty())
    s.clear();

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      char target = board[3 * x + i][3 * y + j];

      if (target == '.')
        continue;

      if (s.count(target))
        return false;

      s.insert(target);
    }

  return true;
}

bool isRowValid(int y, vector<vector<char>> &board)
{
  if (!s.empty())
    s.clear();

  for (int i = 0; i < 9; i++)
  {
    char target = board[i][y];

    if (target == '.')
      continue;

    if (s.count(target))
      return false;

    s.insert(target);
  }

  return true;
}

bool isColumnValid(int x, vector<vector<char>> &board)
{
  if (!s.empty())
    s.clear();

  for (int i = 0; i < 9; i++)
  {
    char target = board[x][i];

    if (target == '.')
      continue;

    if (s.count(target))
      return false;

    s.insert(target);
  }

  return true;
}

class Solution
{
public:
  bool isValidSudoku(vector<vector<char>> &board)
  {
    for (int i = 0; i < 9; i++)
    {
      bool isValid = isRowValid(i, board) && isColumnValid(i, board) && isJiugonggeValid(i / 3, i % 3, board);

      if (!(isValid))
        return false;
    }

    return true;
  }
};