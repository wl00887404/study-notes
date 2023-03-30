#include <iostream>
#include <vector>

using namespace std;

/**
 * 美食等越久越好吃！
 * 負分的餐點不能直接刪掉
 * 做負分的餐點，可以增加後面餐點的時間
 */
 
 /**
  * 這題蠻好玩的
  * 推推
  */
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // 餐點一定低分放前面，高分放後面
        sort(satisfaction.begin(), satisfaction.end());
        
        int size = satisfaction.size();
        int sum = 0;
        vector<int> sumFromTail(size);
        
        int i = size;
        while(i--) {
            sum += satisfaction[i] * (i + 1);
            if(i == size - 1) {
                sumFromTail[i] = satisfaction[i];
            }
            else {
                sumFromTail[i] = sumFromTail[i + 1] + satisfaction[i];
            }
        }

        // 嘗試取消製作某些餐點
        // 如果是負分餐點，會得到不做此餐點的分數，但會導致後續餐點的等待時間減少 1
        // 假設 [-9, -8, -1, 0, 5] ，總分為 -9 * 1 + -8 * 2 + -1 * 3 + 0 * 4 + 5 * 5 = -3
        // -9 不做了，總分變成 -8 * 1 + -1 * 2 + 0 * 3 + 5 * 4 = 10
        // 前後相差 (-9 * 1 + -8 * 1 + -1 * 1 + 0 * 1 + 5 * 1) * -1
        // 有就是從現在的 index 往後 sum
        

        for(int i =0 ;i < size;i++){
            if(satisfaction[i] >= 0) break;

            sum = max(sum, sum - sumFromTail[i]);
        }


        return sum;
    }
};