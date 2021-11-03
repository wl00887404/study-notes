#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 規則改成只有兩次交易機會
 * 一樣不能買兩筆等著賣
 * 與 309 不同是沒有 CD
 */

/**
 * 只能交易兩次 = 前段最佳 + 後段最佳
 * 假設有 7 項
 * 結果為
 *   前 2 項 + 後 5 項
 *   前 3 項 + 後 4 項
 *   前 4 項 + 後 3 項
 *   前 5 項 + 後 2 項
 *   前 6 項（只進行一次交易）
 *   後 6 項（只進行一次交易）
 *   整列（只進行一次交易）
 *
 *   前 1 項 h0 = 0
 *   前 2 項 h1 = max(h0, a1 - a0)
 *   前 3 項 h2 = max(h1, a2 - a0, a2 - a1)
 *   前 4 項 h3 = max(h2, a3 - a0, a3 - a1, a3 - a2)
 *   前 5 項 h4 = max(h3, a4 - a0, a4 - a1, a4 - a2, a4 - a3)
 *   前 6 項 h5 = max(h3, a5 - a0, a5 - a1, a5 - a2, a5 - a3, a5 - a4)
 *
 *   後 1 項 t6 = 0
 *   後 2 項 t5 = max(t6, a6 - a5)
 *   後 3 項 t4 = max(t5, a6 - a4, a5 - a4)
 *   後 4 項 t3 = max(t4, a6 - a3, a5 - a3, a4 - a3)
 *   後 5 項 t2 = max(t3, a6 - a2, a5 - a2, a4 - a2, a3 - a2)
 *   後 6 項 t1 = max(t2, a6 - a1, a5 - a1, a4 - a1, a3 - a1, a2 - a1)
 */

/**
 * TODO: 重寫以前的思路以及研究最佳解
 */

void log(vector<int>& array) {
  for (int i = 0; i < array.size(); i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void log(int* array, int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int result = 0;
    int h[size];
    int t[size];

    h[0] = 0;
    int smallest = prices[0];
    for (int i = 1; i < size; i++) {
      smallest = min(smallest, prices[i]);
      h[i] = max(h[i - 1], prices[i] - smallest);
      result = max(result, h[i]);
    }

    t[size - 1] = 0;
    int biggest = prices[size - 1];
    for (int i = size - 2; 0 <= i; i--) {
      biggest = max(biggest, prices[i]);
      t[i] = max(t[i + 1], biggest - prices[i]);
      result = max(result, t[i]);
    }

    for (int i = 1; i < size - 1; i++) {
      result = max(result, h[i] + t[i + 1]);
    }

    // log(prices);
    // log(h, size);
    // log(t, size);
    // cout << result << endl;

    return result;
  }
} solution;

int main() {
  // vector<int> prices = {7, 6, 5, 4, 3, 4, 5};
  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  // vector<int> prices = {545, 544, 543, 542, 541, 540, 539, 541, 540, 542,
  //                       539, 538, 537, 536, 535, 534, 533, 532, 531, 530,
  //                       529, 528, 527, 526, 525, 0,   0,   0,   0,   0,
  //                       0,   0,   0,   0,   0,   0,   0,   0,   0,   0};

  solution.maxProfit(prices);

  return 0;
}