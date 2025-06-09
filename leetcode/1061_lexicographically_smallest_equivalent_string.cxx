#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * 給定兩字串 s1 s2
 * 其中 s1[i] 跟 s2[i] 可以互相轉換
 * 並且適用交換率、遞移率
 * 也就是 a 可轉換成 b，b 也就可以轉換成 a
 * 如果 a 可以轉換成 c，同時 b 就可以轉換成 c
 */

/**
 * 1, 2 => 2 指向 1
 * 2, 5 => 5 指向 2 => 2 指向 1
 * 3, 5 => 5 指向 3 => 但是 5 指向 1，所以不更新
 *         3 指向 5 => 5 指向 1 => 3 指向 1
 * 0, 4 => 4 指向 0
 * 4, 5 => 5 指向 4 => 4 指向 0
 *      => 4 指向 5 => 5 指向 1 => 但是 4 指向 0，所以不更新
 *      => 2, 5 + 3, 5 都要更新
 *
 * 先把 graph 建好再來剪枝吧
 *
 * 從 a 出發， child 全部都指向 a，然後 BFS 處理
 */

class Node {
 public:
  unordered_set<char> children;
  char destination = '\0';
};

class Solution {
 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<Node*> nodes(26);

    for (int i = 0; i < 26; i++) {
      nodes[i] = new Node();
    }

    int size = s1.size();
    for (int i = 0; i < size; i++) {
      nodes[s1[i] - 'a']->children.insert(s2[i]);
      nodes[s2[i] - 'a']->children.insert(s1[i]);
    }

    queue<Node*> q;
    for (int i = 0; i < 26; i++) {
      char c = 'a' + i;
      // 已經被其他節點捷足先登了
      if (nodes[i]->destination != '\0') continue;

      q.push(nodes[i]);

      while (!q.empty()) {
        Node* node = q.front();
        node->destination = c;
        for (const char& childC : node->children) {
          Node* child = nodes[childC - 'a'];
          // 已經有目的地了
          if (child->destination != '\0') continue;

          q.push(child);
        }
        q.pop();
      }
    }

    size = baseStr.size();
    char result[size + 1];
    result[size] = '\0';

    for (int i = 0; i < size; i++) {
      result[i] = nodes[baseStr[i] - 'a']->destination;
    }

    return string(result);
  }
};