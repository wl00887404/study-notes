#include <iostream>
#include <vector>

using namespace std;

/**
 * s3 依序讀取
 * 可以判斷現在是 s1 的字元，還是 s2 的字元
 */

/**
 * 當兩個一樣， dfs s1 再 s2 的策略竟然失敗的
 */
/**
 * 直接硬塞一個 DP 搞定
 */
class DFSSolution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    s1Pointer = &s1;
    s2Pointer = &s2;
    s3Pointer = &s3;
    s1Size = s1.size();
    s2Size = s2.size();
    s3Size = s3.size();

    if (s1Size + s2Size != s3Size) return false;
    if (s1Size == 0 || s2Size == 0) return helper(0, 0);

    cache.resize(s1Size * s2Size + s2Size, -1);
    return helpWithCache(0, 0);
  };

  string* s1Pointer;
  string* s2Pointer;
  string* s3Pointer;
  int s1Size;
  int s2Size;
  int s3Size;

  bool helper(int i, int j) {
    string& s1 = *s1Pointer;
    string& s2 = *s2Pointer;
    string& s3 = *s3Pointer;

    while (i < s1Size && j < s2Size) {
      bool isS1Matched = s1[i] == s3[i + j];
      bool isS2Matched = s2[j] == s3[i + j];

      if (!isS1Matched && !isS2Matched) return false;

      // s1 與 s2 都有機會
      if (isS1Matched && isS2Matched) {
        if (helpWithCache(i + 1, j)) return true;
        if (helpWithCache(i, j + 1)) return true;
      }

      if (isS1Matched) {
        i++;
      } else {
        j++;
      }
    }

    // s1 用完了，比對 s2
    if (i == s1Size) return isStringMatch(s2Pointer, j);

    // s2 用完了，比對 s1
    return isStringMatch(s1Pointer, i);
  }

  bool isStringMatch(string* stringPointer, int& i) {
    string& s = *stringPointer;
    string& s3 = *s3Pointer;
    int& size = stringPointer == s1Pointer ? s1Size : s2Size;

    for (; i < size; i++) {
      if (s[i] != s3[s3Size - (size - i)]) return false;
    }

    return true;
  }

  vector<int> cache;
  bool helpWithCache(int i, int j) {
    int key = i * s2Size + j;

    if (cache[key] == -1) cache[key] = helper(i, j);

    return cache[key];
  }
};

/**
 * 如果用假設可以 match 呢？
 * s1 => i, s2 => j, s3 => k
 * 如果 s1 跟 s2 同時有可能，那就 ambiguousIndex++
 * 比對 i + ambiguousIndex == s3[k] 或 j + ambiguousIndex == s3[k]
 * 如果 s1 match 但 s2 沒有 match ，那就確定 ambiguousIndex 是屬於 s1 的
 * 如果還是一起 match ，那就繼續累積 ambiguousIndex
 */
/**
 * 這個寫法在 s1 = aa, s2 = ab, s3 = aaba (a ab a) (s1 + s2 + s1)爆開了
 * s3[0] = a; ambiguousIndex++
 * s3[1] = a; 會把 ambiguousIndex 判斷給 s1
 *
 * 因為 s1[0] + s1[1] == s1[0] + s2[0]
 * aa 可以是 s1 也可以是 s1[0] + s2[0] ，要決定要看 b 的位置
 *
 * s1 = aabaa, s2 = aabac, s3 = aabaabacaa (aab aabac aa) (s1 + s2 + s1)
 * 重點應該是尾巴跟頭一樣
 */
class AmbiguousSolution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int s1Size = s1.size();
    int s2Size = s2.size();
    int s3Size = s3.size();

    if (s1Size + s2Size != s3Size) return false;

    int ambiguousIndex = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i + ambiguousIndex < s1Size && j + ambiguousIndex < s2Size) {
      // cout << i << " " << j << " " << ambiguousIndex  << " "  << i + j +
      // ambiguousIndex << endl;
      bool isS1Matched = s1[i + ambiguousIndex] == s3[i + j + ambiguousIndex];
      bool isS2Matched = s2[j + ambiguousIndex] == s3[i + j + ambiguousIndex];

      if (!isS1Matched && !isS2Matched) return false;

      // s1 與 s2 都有機會 match
      if (isS1Matched && isS2Matched) {
        // cout << i << " ";
        // cout << j << " ambiguousIndex++" << endl;
        ambiguousIndex++;
        continue;
      }

      if (ambiguousIndex != 0) {
        // s1 = aa, s2 = ab, s3 = aaba
        // 前兩個 aa 不能判斷是 s1 還是 s1[0] + s2[0]
        // 決定的因素是 b 的位置
        if (isS1Matched &&
            s1[i + ambiguousIndex - 1] == s1[i + ambiguousIndex]) {
        }
      }

      // 只有其中一個字串 match ，把 ambiguousIndex 都歸他
      if (isS1Matched) {
        i += ambiguousIndex + 1;
        // if (ambiguousIndex != 0) cout << "ambiguousIndex 鮭魚 s1 " << i <<
        // endl;
      } else {
        j += ambiguousIndex + 1;
        // if (ambiguousIndex != 0) cout << "ambiguousIndex 鮭魚 s2 " << j <<
        // endl;
      }

      k++;
      ambiguousIndex = 0;
    }

    // s1 用完了，比對 s2
    if (i + ambiguousIndex == s1Size) return isStringMatch(s2, j, s3);

    // s2 用完了，比對 s1
    return isStringMatch(s1, i, s3);
  };

  bool isStringMatch(string& s, int& i, string& s3) {
    int size = s.size();
    int s3Size = s3.size();

    for (; i < size; i++) {
      if (s[i] != s3[s3Size - (size - i)]) return false;
    }

    return true;
  }
};

class Solution : public DFSSolution {};