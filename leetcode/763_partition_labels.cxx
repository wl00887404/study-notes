#include <iostream>
#include <vector>

using namespace std;

/**
 * 題目看半天看不懂
 * 原來是每種字母只能出現在切出來的某一個區塊
 * 一看就知道跟 56 題有關係
 */

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    vector<int> begins;
    int endsByAlphabet[26];

    for (int i = 0; i < 26; i++) {
      endsByAlphabet[i] = -1;
    }

    int size = s.size();
    for (int i = 0; i < size; i++) {
      char& c = s[i];
      // 如果字母沒有出現過
      // 記錄開始位置
      if (endsByAlphabet[c - 'a'] == -1) {
        begins.push_back(i);
      }

      // 紀錄結尾位置
      endsByAlphabet[c - 'a'] = i;
    }

    vector<int> result;
    size = begins.size();
    int begin = begins[0];
    int end = endsByAlphabet[s[begin] - 'a'];

    for (int i = 1; i < size; i++) {
      if (begins[i] > end) {
        // 如果下一個 begin 在 end 後面
        // 可以形成 intervals
        // 像是 abc 的情況
        // begins 會是 [0, 1, 2]
        // ends 也會是 [0, 1, 2]
        result.push_back(end - begin + 1);
        begin = begins[i];
        end = endsByAlphabet[s[begin] - 'a'];
      } else {
        // 如果下一個 begin 在 end 之前
        // 可以連接在一起
        end = max(end, endsByAlphabet[s[begins[i]] - 'a']);
      }
    }

    result.push_back(end - begin + 1);

    return result;
  }
};