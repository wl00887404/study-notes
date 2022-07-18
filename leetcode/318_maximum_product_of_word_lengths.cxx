#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    int size = words.size();
    int values[size];

    // length, index
    vector<pair<int, int>> orders(size);

    for (int i = 0; i < size; i++) {
      values[i] = 0;
      orders[i] = {words[i].size() * -1, i};

      for (char& c : words[i]) {
        values[i] |= 1 << (c - 'a');
      }
    }

    sort(orders.begin(), orders.end());

    int result = 0;

    for (int i = 0; i < size; i++) {
      int& length1 = orders[i].first;
      int& value1 = values[orders[i].second];

      for (int j = i + 1; j < size; j++) {
        int& value2 = values[orders[j].second];
          
         
        if ((value1 & value2) != 0) continue;

        int& length2 = orders[j].first;
        result = max(result, length1 * length2);

        break;
      }
    }

    return result;
  }
};