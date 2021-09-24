#include <iostream>
#include <vector>
using namespace std;

/**
 * 同時擁有
 */

class Solution {
 public:
  string tictactoe(vector<vector<int>>& moves) {
    int size = moves.size();
    bool chesses[9];

    for (int i = 0; i < 9; i++) chesses[i] = false;
    for (int i = 0; i < size; i += 2) {
      chesses[moves[i][0] * 3 + moves[i][1]] = true;
    }

    if (isWin(chesses)) return "A";

    for (int i = 0; i < 9; i++) chesses[i] = false;
    for (int i = 1; i < size; i += 2) {
      chesses[moves[i][0] * 3 + moves[i][1]] = true;
    }

    if (isWin(chesses)) return "B";

    return size == 9 ? "Draw" : "Pending";
  }

  bool isWin(bool* chesses) {
    for (int i = 0; i < 3; i++) {
      if (chesses[i * 3] && chesses[i * 3 + 1] && chesses[i * 3 + 2]) {
        return true;
      }
      if (chesses[i] && chesses[i + 3] && chesses[i + 6]) return true;
    }

    if (chesses[0] && chesses[4] && chesses[8]) return true;
    if (chesses[2] && chesses[4] && chesses[6]) return true;

    return false;
  }
};