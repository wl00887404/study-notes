#include <iostream>
using namespace std;

class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    int frequencies[5];
    for (int i = 0; i < 5; i++) frequencies[i] = 0;

    string::iterator pointer = text.begin();
    string::iterator end = text.end();

    while (pointer != end) {
      if (*pointer == 'b') {
        frequencies[0]++;
      } else if (*pointer == 'a') {
        frequencies[1]++;
      } else if (*pointer == 'l') {
        frequencies[2]++;
      } else if (*pointer == 'o') {
        frequencies[3]++;
      } else if (*pointer == 'n') {
        frequencies[4]++;
      }
      pointer++;
    }

    frequencies[2] /= 2;
    frequencies[3] /= 2;

    int min = frequencies[0];
    for (int i = 1; i < 5; i++) {
      if (min <= frequencies[i]) continue;
      min = frequencies[i];
    }

    return min;
  }
};