#include <iostream>

#include "./log.cxx"
using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int ransomNoteLength = ransomNote.size();

    if (ransomNoteLength == 0) return true;

    int magazineLength = magazine.size();

    if (magazineLength == 0) return false;

    int frequencies[26] = {0};

    for (int i = 0; i < ransomNoteLength; i++) {
      frequencies[ransomNote[i] - 'a']++;
    }

    for (int i = 0; i < magazineLength; i++) {
      int index = magazine[i] - 'a';
      if (frequencies[index] == 0) continue;
      frequencies[index]--;
      ransomNoteLength--;

      if (ransomNoteLength == 0) return true;
    }

    return false;
  }
} solution;

int main() {
  cout << solution.canConstruct(
              "bg", "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj")
       << endl;

  return 0;
}