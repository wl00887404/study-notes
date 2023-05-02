#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int maximum = 999;
        int minimum = 1000001;
        int size = salary.size();
        int sum = 0;

        for(int& s :salary ){
            sum += s;
            minimum = min(minimum, s);
            maximum = max(maximum, s);
        }

        return (double)(sum - minimum - maximum) / (size - 2);
    }
};