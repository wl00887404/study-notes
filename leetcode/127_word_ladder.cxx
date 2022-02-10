#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 詞梯是一款遊戲
 * 可以改一個字母，轉換成另外一個字
 * 題目問要改幾次
 *
 * 就是圖
 * 從 A 點到 B 最短距離
 * BFS 應該就可以了吧
 */

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    length = beginWord.size();
    int wordListSize = wordList.size();
    vector<string*> wordPointers;

    int endIndex = -1;
    int i = 0;  // 前面是被刪除的節點

    for (int j = 0; j < wordListSize; j++) {
      wordPointers.push_back(&wordList[j]);
      if (wordList[j] == endWord) endIndex = j;
    }

    if (endIndex == -1) return 0;

    queue<string*> queue;
    queue.push(&beginWord);
    int result = 1;

    while (!queue.empty()) {
      int queueSize = queue.size();
      result++;

      while (queueSize--) {
        for (int j = i; j < wordListSize; j++) {
          if (!canLadder(queue.front(), wordPointers[j])) continue;

          // 此節點就是解
          if (endIndex == j) return result;

          queue.push(wordPointers[j]);  // 將可以達到的節點存進 queue
          wordPointers[j] = wordPointers[i];  // 刪除此節點

          // 因為將前面的節點往後搬了
          // 所以要檢查 endIndex 有沒有需要更新
          if (i == endIndex) endIndex = j;
          i++;
        }

        queue.pop();
      }
    }

    return 0;
  }

  int length;

  bool canLadder(string*& s1, string*& s2) {
    bool hasChance = true;

    for (int i = 0; i < length; i++) {
      if ((*s1)[i] == (*s2)[i]) continue;

      if (!hasChance) return false;

      hasChance = false;
    }

    return true;
  }
};

/**
 * 這個作法就是答案了
 * 只是一個從左一個從右跑
 * 是因為這樣跑比較快嗎？
 * https://leetcode.com/problems/word-ladder/discuss/40707/C++-BFS
 */

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.count(endWord) == 0) return 0;

    unordered_set<string> beginSet{}, endSet{};
    beginSet.insert(beginWord);
    endSet.insert(endWord);

    int level = 0;
    // no queue is needed!!!
    while (!beginSet.empty() && !endSet.empty()) {
      ++level;

      unordered_set<string> nextSet{};

      for (auto word : beginSet) {
        for (auto& c : word) {
          const auto c0 = c;
          for (char ch = 'a'; ch < 'z'; ++ch) {
            if (ch == c) continue;

            c = ch;
            if (endSet.count(word) > 0) return level + 1;

            auto it = dict.find(word);
            if (it != dict.end()) {
              dict.erase(it);
              nextSet.insert(word);
            }
          }
          c = c0;  // chance word back to its original by changing its letter
                   // from c back to c0
        }
      }

      if (nextSet.size() < endSet.size())  // key!!!!
        beginSet = nextSet;
      else {
        beginSet = endSet;
        endSet = nextSet;
      }
    }

    return 0;
  }
};