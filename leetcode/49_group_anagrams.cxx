#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 * 直覺上，質數 hash 就可以解了，
 * 如果 overflow ，可以多分幾段，
 * 最佳解是另一種神奇的 hash ，
 *
 * 另外發現 unordered_map::begin 好像很慢耶
 * 蠻奇怪的
 *
 * TODO: 有空研究一下那個 hash
 */

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int primeNums[] = {2,  3,  5,  7,  11, 13,  17,  19, 23, 29,
                       31, 37, 41, 43, 47, 53,  59,  61, 67, 71,
                       73, 79, 83, 89, 97, 101, 103, 107};

    vector<vector<string>> results;
    unordered_map<unsigned int, vector<string>> map;
    vector<unsigned int> keys;

    int length = strs.size();

    for (int i = 0; i < length; i++) {
      unsigned int key = getHash(primeNums, strs[i]);

      if (!map.count(key)) keys.push_back(key);

      map[key].push_back(strs[i]);
    }

    length = keys.size();

    for (int i = 0; i < length; i++) {
      results.push_back(map[keys[i]]);
    }

    return results;
  }

  unsigned int getHash(int primeNums[], string& str) {
    int length = str.size();
    unsigned int result = 1;

    for (int i = 0; i < length; i++) {
      result *= primeNums[str[i] - 'a'];
    }

    return result;
  }
};