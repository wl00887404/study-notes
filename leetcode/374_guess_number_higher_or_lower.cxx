/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

/**
 * 這題就是 AlphaCamp 的猜數字
 */

int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    int left = 1;
    long long right = (long long)n + 1;

    while (left < right) {
      int mid = (right + left) / 2;
      int result = guess(mid);

      if (result == 0) return mid;

      if (result == -1) {
        right = mid;
        continue;
      }

      left = mid + 1;
    }

    return -1;
  }
};