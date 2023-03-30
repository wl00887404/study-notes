
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class OriginalSolution {
 public:
  vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> result;
    unordered_map<char, char> map;
    unordered_set<char> hasMapped;
    int size = pattern.size();

    for (string& s : words) {
      int i = 0;
      map.clear();
      hasMapped.clear();

      while (i < size) {
        if (!map.count(pattern[i])) {
          if (hasMapped.count(s[i])) {
            // s[i] 已經有其他字元 map 了
            break;
          }
          // pattern[i] 沒出現過，現在對應到 s[i]
          map[pattern[i]] = s[i];
          hasMapped.insert(s[i]);
          i++;
        } else if (map[pattern[i]] != s[i]) {
          // pattern[i] 跟 s[i] 不 match ，應該對應到 map[pattern[i]]
          break;
        } else {
          // pattern[i] match 到 s[i] 成功
          i++;
        }
      }

      if (i == size) result.push_back(s);
    }

    return result;
  }
};