#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class BuildInSolution {
 public:
  string getPermutation(int n, int k) {
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
      p[i] = i + 1;
    }

    k--;
    while (k--) {
      next_permutation(p.begin(), p.end());
    }

    string result = "";

    for (int& i : p) {
      result += to_string(i);
    }

    return result;
  }
};

class BuildInSolution {
 public:
  string getPermutation(int n, int k) {
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
      p[i] = i + 1;
    }

    k--;
    while (k--) {
      next_permutation(p.begin(), p.end());
    }

    string result = "";

    for (int& i : p) {
      result += to_string(i);
    }

    return result;
  }
};

/**
 * 1: 123
 * 2: 132
 * 3: 213
 * 4: 231
 * 5: 312
 * 6: 321
 *
 * 1, 2 是 1 開頭
 * 3, 4 是 2 開頭
 * 5, 6 是 3 開頭
 * 因為後面是兩位數字 2!
 * (k - 1) / (n - 1)! 就可以得到首位數字
 *
 * 接下來依樣畫葫蘆， 假設 k = 3 ，就繼續處理 13
 */

class Solution {
 public:
  string getPermutation(int n, int k) {
    int size = n;  // 可用的數字總量
    bool isUsed[size];
    k--;

    for (int i = 0; i < size; i++) {
      isUsed[i] = false;
    }

    string result = "";

    while (n != 0) {
      int numIndex = k / p[n];
      int num = 0;

      // 找到還沒使用過的數字
      while (true) {
        if (isUsed[num]) { // 用過的數字直接略過
          num++;
          continue;
        }

        if (numIndex == 0) break;
        // 這個數字沒有用過，使用跳過機會
        numIndex--;
        num++;
      }

      isUsed[num] = true;
      result += to_string(num + 1);
      k = k % p[n];
      n--;
    }

    return result;
  }

  // p[n] = (n - 1)!
  const int p[10] = {
      1,      // 不會用到，來撐 n 的
      1,      // n = 1, 0!
      1,      // n = 2, 1!
      2,      // n = 3, 2!
      6,      // n = 4, 3!
      24,     // n = 5, 4!
      120,    // n = 6, 5!
      720,    // n = 7, 6!
      5040,   // n = 8, 7!
      40320,  // n = 9, 8!

  };
};