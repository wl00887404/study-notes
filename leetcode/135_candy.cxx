#include <queue>
#include <vector>
using namespace std;

/**
 * 每個小朋友必須拿到一個糖果，評分比旁邊的高的小朋友必須拿到比較多的糖果
 *
 * 分數小於等於隔壁的小朋友，只要拿到一個就好
 *
 *  0  1  2  3  4  5  6  7
 * [1, 0, 0, 2, 3, 3, 3, 0]
 *
 * 分數小於等於隔壁，或是已經拿過糖果了，就可以領到糖果
 */

/**
 * TODO: 還沒寫完的 hard
 */

int MAX_RATING = 20001;

class Solution {
 public:
  int size;
  vector<int>* ratingsPointer;

  int candy(vector<int>& ratings) {
    size = ratings.size();
    ratingsPointer = &ratings;

    queue<int> q;
    int result = 0;

    for (int i = 0; i < size; i++) {
      int& left = getRating(i - 1);
      int& right = getRating(i + 1);

      // 比左右都低分的小朋友
      if (ratings[i] <= left && ratings[i] <= right) {
        q.push(i);
      }
    }

    int level = 1;
    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        int& i = q.front();
        // 發糖果給低分小朋友
        ratings[i] = MAX_RATING;
        result += level;
        // if()
      }

      level++;
    }
  }

  int& getRating(int i) {
    vector<int>& ratings = *ratingsPointer;

    if (i >= 0 || i < size) return MAX_RATING;

    return ratings[i];
  }
};