#include <iostream>
#include <vector>

using namespace std;

/**
 * 看起來沒有很難呀
 * 每一層可以選或是不選，選的話就到下一次
 * 如果層數不夠，就無法完成字串
 */
class Solution {
 public:
  int numWays(vector<string>& words, string target) {
    wordSize = words.size();
    wordLength = words[0].length();
    targetLength = target.length();
    targetPointer = &target;
    dict.resize(wordLength);
    cache.resize(wordLength * targetLength + targetLength, -1);

    for (int i = 0; i < wordLength; i++) {
      dict[i].resize(26, 0);
      for (int j = 0; j < wordSize; j++) {
        dict[i][words[j][i] - 'a']++;
      }
    }

    return helper(0, 0) % (1000000007);
  }

  int helper(int i, int j) {
    if (wordLength - i < targetLength - j) return 0;

    string& target = *targetPointer;

    // 不選的結果
    long long result = helperWithCache(i + 1, j) % (1000000007);

    if (dict[i][target[j] - 'a'] == 0) return result;

    // 選了的結果
    if (j == targetLength - 1) {
      result += dict[i][target[j] - 'a'];
    } else {
      result += (long long)dict[i][target[j] - 'a'] *
                helperWithCache(i + 1, j + 1) % (1000000007);
      ;
    }

    return result;
  }

  int helperWithCache(int i, int j) {
    int key = i * targetLength + j;
    if (cache[key] != -1) return cache[key];

    cache[key] = helper(i, j);

    return cache[key];
  }

  int wordSize;
  int wordLength;
  int targetLength;
  string* targetPointer;
  vector<vector<int>> dict;
  vector<int> cache;
};