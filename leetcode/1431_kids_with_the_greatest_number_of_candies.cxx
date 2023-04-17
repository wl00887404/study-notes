#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandy = 0;

    for (int& candy : candies) maxCandy = max(candy, maxCandy);

    vector<bool> result;

    for (int& candy : candies) {
      result.push_back(candy + extraCandies >= maxCandy);
    }

    return result;
  }
};