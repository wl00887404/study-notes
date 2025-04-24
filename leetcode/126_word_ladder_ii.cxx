#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

/**
 * wordList[i] 與 wordList[j] 相差一個字母就可以爬梯子
 * 一直爬一直爬，直到爬到 endWord，要是 endWord 沒有在 wordList 之中，要回傳 []
 */

int LONGEST_DISTANCE = 600;

class Node {
 public:
  string* sp;
  vector<Node*> children;

  int distanceToBegin = LONGEST_DISTANCE;
  int distanceToEnd = LONGEST_DISTANCE;

  vector<vector<string>>* rp;
};

class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    wordList.push_back(beginWord);  // 暫時把 beginWord 放進去方便之後處理

    int size = wordList.size();
    vector<Node*> nodes(size);

    int beginIndex = size - 1;
    int endIndex = -1;

    for (int i = 0; i < size; i++) {
      string& s = wordList[i];
      nodes[i] = new Node();
      nodes[i]->sp = &s;

      if (s == endWord) {
        endIndex = i;
      }
    }

    if (endIndex == -1) return {};

    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (!isDifferOneChar(wordList[i], wordList[j])) {
          continue;
        }

        nodes[i]->children.push_back(nodes[j]);
        nodes[j]->children.push_back(nodes[i]);
      }
    }

    // 廣度優先，寫入 node 離 begin 的距離
    bfs(nodes[beginIndex], nodes[endIndex], true);

    int shortestDistance = nodes[endIndex]->distanceToBegin;

    if (shortestDistance == LONGEST_DISTANCE) {
      // begin 到不了 end
      return {};
    }

    // 廣度優先，寫入 node 離 end 的距離
    bfs(nodes[endIndex], nodes[beginIndex], false);

    vector<string> current;
    vector<vector<string>> result;

    dfs(nodes[beginIndex], shortestDistance, current, result);

    return result;
  }

  // forward 為 true，表示從 begin 走到 end
  void bfs(Node* begin, Node* end, bool forward) {
    queue<Node*> q;
    unordered_set<Node*> isVisited;

    int level = 0;
    q.push(begin);
    bool hasReachedEnd = false;

    while (!q.empty() && !hasReachedEnd) {
      int size = q.size();

      while (size--) {
        Node* node = q.front();

        // 此 node 已經被最短路徑拜訪過了
        if (isVisited.count(node)) {
          q.pop();
          continue;
        }

        if (node == end) hasReachedEnd = true;

        if (forward) {
          node->distanceToBegin = level;
        } else {
          node->distanceToEnd = level;
        }

        for (Node* child : node->children) {
          q.push(child);
        }

        isVisited.insert(node);
        q.pop();
      }

      level++;
    }
  }


  // 依據 node 離 begin、end 的距離，深度優先建立結果
  void dfs(Node* node, const int& shortestDistance, vector<string>& current,
               vector<vector<string>>& result) {
    if (node->distanceToBegin == shortestDistance && node->distanceToEnd == 0) {
      // 終點到了
      current.push_back(*node->sp);
      result.push_back(current);
      current.pop_back();
      return;
    }

    if (node->distanceToBegin + node->distanceToEnd != shortestDistance) {
      // 這個節點不會到終點
      return;
    }

    current.push_back(*node->sp);

    for (Node* child : node->children) {
      if (node->distanceToBegin + 1 != child->distanceToBegin ||
          node->distanceToEnd - 1 != child->distanceToEnd) {
        continue;
      }

      dfs(child, shortestDistance, current, result);
    }

    current.pop_back();
  }

  bool isDifferOneChar(const string& s1, const string& s2) {
    int i = 0;
    int size = s1.size();

    while (i < size && s1[i] == s2[i]) {
      i++;
    }

    if (i == size) return false;  // 兩個字完全一樣

    i++;  // 跳過不一樣的字元
    while (i < size && s1[i] == s2[i]) {
      i++;
    }

    return i == size;  // 後面的字元們都一樣
  }
};