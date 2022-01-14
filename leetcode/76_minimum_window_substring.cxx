#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

/**
 * 當 begin 遇到 t 要求的字元
 * 不斷 end 往右走直到滿足 t
 *
 * 要是 end 遇到已經滿出來的字元
 * 那 begin 可以往右走
 * s="bdadbddc", t="abc"
 *
 * bdadbddc
 * b   ^
 *
 * b 已經滿足了
 * begin 可以往右到 a
 * 乾脆把有可能的 head 的儲存起來吧
 */

/**
 * TODO: 看一下最佳解
 * 好像只要 4ms
 */

class Solution {
 public:
  string minWindow(string s, string t) {
    int sSize = s.size();
    int tSize = t.size();
    if (sSize < tSize) return "";

    int sFrequency[52];
    int tFrequency[52];

    for (int i = 0; i < 52; i++) {
      sFrequency[i] = tFrequency[i] = 0;
    }

    for (const char& c : t) tFrequency[getKey(c)]++;

    // begin 有可能出現的 index
    queue<int> queue;
    int resultBegin = -1;
    int resultLength = sSize + 1;  // 不可能的長度
    int countIncludeT = 0;         // 現在有幾個 t 的字元在範圍內

    for (int i = 0; i < sSize; i++) {
      int key = getKey(s[i]);

      // s[i] 不是目標字元之一
      if (tFrequency[key] == 0) continue;

      queue.push(i);
      sFrequency[key]++;

      // 現在 s[i] 包含 t 的字元
      // countIncludT 必須 ++
      if (sFrequency[key] <= tFrequency[key]) countIncludeT++;

      // begin 已經被滿足了
      // 可以 begin 可以往後走
      while (!queue.empty()) {
        int key = getKey(s[queue.front()]);
        if (sFrequency[key] <= tFrequency[key]) break;

        sFrequency[key]--;
        queue.pop();
      }

      if (countIncludeT == tSize) {
        if ((i + 1 - queue.front()) < resultLength) {
          resultBegin = queue.front();
          resultLength = i + 1 - queue.front();
        }
      }
    }

    if (resultBegin == -1) return "";

    return s.substr(resultBegin, resultLength);
  }

  int getKey(const char& c) {
    if (c >= 'a') return c - 'a' + 26;

    return c - 'A';
  }
};
