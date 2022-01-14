#include <iostream>

using namespace std;

/**
 * 題意：
 *   找一個最長的 substring
 *   每個字元出現的次數大於等於 k
 *
 * 這題的困難點在遇到一個字元
 * 不知道它有沒有辦法達到 k 的次數
 * 要知道只能先 O(n) 跑過整個字串
 *
 * 如果知道此字元無法達到 k 次數，即可切割字串
 * 不斷重複可以 divide and conquer
 */

/**
 * 這樣寫就是最快了
 * 還真的沒辦法再更快耶
 */

class Solution {
 public:
  int longestSubstring(string s, int k) {
    size = s.size();
    sPointer = &s;
    this->k = k;

    if (k == 1) return size;

    return helper(0, size);
  }

  string* sPointer;
  int k;
  int size;

  int helper(int begin, int end) {
    if (begin == end) return 0;

    string& s = *sPointer;
    int frequency[26];
    for (int i = 0; i < 26; i++) frequency[i] = 0;

    for (int i = begin; i < end; i++) {
      const char& c = s[i];
      frequency[c - 'a']++;
    }

    bool allGreaterThanK = true;
    for (int i = 0; i < 26; i++) {
      if (frequency[i] == 0) continue;
      if (frequency[i] >= k) continue;

      allGreaterThanK = false;
      break;
    }

    if (allGreaterThanK) return end - begin;

    int result = 0;
    int nextBegin = begin;
    for (int i = begin; i < end; i++) {
      if (frequency[s[i] - 'a'] >= k) continue;
      // 這個字元無法達到 k 次數
      result = max(result, helper(nextBegin, i));
      nextBegin = i + 1;
    }
    // 處理像中間到最後的的 case
    // bbaaa$
    //   ^  ^
    result = max(result, helper(nextBegin, end));

    return result;
  }
};