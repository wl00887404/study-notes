#include <iostream>
#include <vector>

using namespace std;

/**
 * 如果這個兩個字串只有 swap 一次那他們就是一個 group
 * A 可以 swap 成 B 也可以 swap 成 C ，那 B C 雖然差兩個 swap 但也是一個 group
 *
 * 每個字串互相判斷是否為相似字串一次？
 * 72 題感覺很接近，可以插入、刪除、替換字元，看要操作幾次可以變成目標字串
 * 這題是 swap ，也就是替換兩次
 *
 * 直接比對兩個字串
 * 兩者同位置不同字元，可以容忍 2 次
 * strs = ["tars", "rats", "arts", "star"]
 *
 * 兩兩字串比較，之後 union find ？
 */

/**
 * 找到了 union find 的好文章
 *   https://hackmd.io/@CLKO/rkRVS_o-4?type=view
 * 跟 2316 題遇到一樣的問題
 */

class Solution {
 public:
  int numSimilarGroups(vector<string>& strs) {
    int size = strs.size();
    parents.resize(size);
    for (int i = 0; i < size; i++) parents[i] = i;

    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (!isSimilar(strs[i], strs[j])) continue;
        parents[findParent(i)] = findParent(j);
      }
    }

    int result = 0;

    for (int i = 0; i < size; i++) {
      if (parents[i] == i) result++;
    }

    return result;
  }

  vector<int> parents;

  int findParent(int n) {
    if (parents[n] == n) return n;

    int root = findParent(parents[n]);
    parents[n] = root;

    return root;
  }

  bool isSimilar(string& str1, string& str2) {
    int chances = 2;
    int size = str1.size();

    for (int i = 0; i < size; i++) {
      if (str1[i] == str2[i]) continue;
      chances--;
      if (chances < 0) return false;
    }

    return true;
  }
};
