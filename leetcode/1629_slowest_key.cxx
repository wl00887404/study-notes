#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int length = keysPressed.length();

    char result = keysPressed[0];
    int maxTime = releaseTimes[0];

    for (int i = 1; i < length; i++) {
      int time = releaseTimes[i] - releaseTimes[i - 1];

      if (time < maxTime) continue;

      result = time > maxTime ? keysPressed[i] : max(keysPressed[i], result);
      maxTime = time;
    }
    
    return result;
  }
};