#include <iostream>
#include <vector>
using namespace std;

/**
 * 走過的路徑無法再次使用
 * 
 * 實際走字謎
 * 使用過的字暫時替換掉
 */

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int xLength = board.size();
    int yLength = board[0].size();

    if (word.length() > xLength * yLength) return false;

    string::iterator begin = word.begin();
    string::iterator end = word.end();

    for (int x = 0; x < xLength; x++) {
      for (int y = 0; y < yLength; y++) {
        if (find(board, x, y, begin, end, xLength, yLength)) return true;
      }
    }

    return false;
  }

 private:
  bool find(vector<vector<char>>& board, int& x, int& y,
            string::iterator& begin, string::iterator& end, int& xLength,
            int& yLength) {
    if (begin == end) return true;
    if (!inRange(x, y, xLength, yLength)) return false;

    char c = board[x][y];
    if (c != *begin) return false;

    begin++;
    board[x][y] = '\0';

    y++;
    if (find(board, x, y, begin, end, xLength, yLength)) return true;
    y--;

    x++;
    if (find(board, x, y, begin, end, xLength, yLength)) return true;
    x--;

    y--;
    if (find(board, x, y, begin, end, xLength, yLength)) return true;
    y++;

    x--;
    if (find(board, x, y, begin, end, xLength, yLength)) return true;
    x++;

    board[x][y] = c;
    begin--;

    return false;
  }

  bool inRange(int& x, int& y, int& xLength, int& yLength) {
    if (x < 0 || y < 0 || x >= xLength || y >= yLength) {
      return false;
    }

    return true;
  }
} solution;

int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCB";

  cout << solution.exist(board, word) << endl;

  return 0;
}