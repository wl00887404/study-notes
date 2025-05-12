#include <vector>
using namespace std;

/**
 * 有分 I 與 L ，可以拼 2 * N 的圖型，問一共有幾種組合
 */

/**
 * 怎麼好像寫過，我真的記得我寫過
 */
/*
 * n = 1
 * a => 圖元 M
 * a
 */

/*
 * n = 2
 * a b => M + M => M + n(1)
 * a b
 *
 * a a => 圖元 N
 * b b
 *       M
 * = 1 + n(1)
 */

/**
 * n = 3
 * a b c => M + M + M => M + n(2)
 * a b c
 *
 * a b b => M + N => M + n(2)
 * a c c => N + M => N + n(1)
 *
 * a b b => 圖元 O
 * a a b
 *
 * a a b => 圖元 P
 * a b b
 *       M      N
 * = 2 + n(2) + n(1)
 */

/**
 * n = 4
 * a b c d => M + M + M + M =>  M + n(3)
 * a b c d
 *
 * a b c c => M + M + N => M + N + M  => M + n(3)
 * a b d d= > N + M + M => N + n(2)
 *
 * a a c c => N + N => N + n(2)
 * b b d d
 *
 * a b c c => M + O => M + n(3)
 * a b b c => O + M => O + n(1)
 *
 * a b b c => M + P => M + n(3)
 * a b c c => P + M => P + n(1)
 *
 * a b b c => 圖元 Q
 * a a c c
 *
 * a a c c => 圖元 R
 * a b b c
 *       M      N      O      P
 * = 2 + n(3) + n(2) + n(1) + n(1)
 */

/**
 * n = 5
 * M + M + M + M + M => 1
 * M + M + M + N => 4
 * M + N + N  => 3
 * M + M + O  => 3
 * M + M + P  => 3
 * N + O => 2
 * N + P => 2
 * M + Q => 2
 * M + R => 2
 *
 * a b b d d => 圖元 S
 * a a c c d
 *
 * a a c c d => 圖元 T
 * a b b d d
 *       M      N      O      P      Q      R
 * = 2 + n(4) + n(3) + n(2) + n(2) + n(1) + n(1)
 */

/**
 * n = 6
 *
 * a b b d d e => 圖元 U
 * a a c c e e
 *
 * a a c c e e => 圖元 V
 * a b b d d e
 *       M      N      O      P      Q      R      S      t
 * = 2 + n(5) + n(4) + n(3) + n(3) + n(2) + n(2) + n(1) + n(1)
 */

class Solution {
 public:
  int numTilings(int n) {
    vector<int> results = {0, 1, 2};

    for (int i = 3; i <= n; i++) {
      long long result = (2 + results[i - 1] + results[i - 2]) % 1000000007;

      for (int j = i - 3; j > 0; j--) {
        result = (result + 2 * results[j]) % 1000000007;
      }

      results.push_back(result);
    }

    return results[n];
  }
};