#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  long long mostPoints(vector<vector<int>>& questions) {
    size = questions.size();
    cache.resize(size, -1);
    questionsPointer = &questions;

    return helper(0);
  }

  long long helper(int i) {
    if (i >= size) return 0;
    if (cache[i] != -1) return cache[i];

    vector<vector<int>>& questions = *questionsPointer;
    // 分成選跟不選
    cache[i] = questions[i][0] + helper(i + questions[i][1] + 1);

    cache[i] = max(cache[i], helper(i + 1));

    return cache[i];
  }

  vector<long long> cache;
  int size;
  vector<vector<int>>* questionsPointer;
};