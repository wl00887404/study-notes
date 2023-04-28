#include <iostream>
#include <vector>

using namespace std;
/**
 * n = 4 的情況
 * 第一輪 [1, 1, 1, 1]
 * 第二輪 [1, 0. 1, 0]
 * 第三輪 [1, 0, 0 ,0]
 * 第四輪 [1, 0, 0, 1]
 */

 /**
  * 每個數字做質因數分解會比較好嗎？
  */
class CountingSolution {
public:
    int bulbSwitch(int n) {
        vector<bool> bulbs(n,  true);

        for(int i = 2; i <= n; i++){
            for(int j = i; j <= n; j+= i) {
                bulbs[j - 1] = !bulbs[j - 1];
            }
        }

        int result = 0;
        for(const bool& bulb: bulbs){
            if(bulb) result++;
        }

       return result; 
    }
};

/**
 * 等一下，這是要找平方數嗎？
 * 平方數才會有奇數個因數，才可以開燈
 * 1 = 1 ⭕️
 * 2 = 1 2
 * 3 = 1 3
 * 4 = 1 2 4 ⭕️
 * 5 = 1 5
 * ...
 * 8 = 1 2 4 8
 * 9 = 1 3 9
 * ...
 * 12 = 1 2 3 4 6 12
 * 16 = 1 2 4 8 16 ⭕️
 */

class Solution {
public:
    int bulbSwitch(int n) {
        int result = 0;

        for(int i = 1; i * i <= n; i++) {
            result++;
        }


        return result; 
    }
};