#include <iostream>
#include <vector>
using namespace std;

/**
 * 回傳 subsequence
 * 每個 words[] 會對應到 groups[]
 * 要求是 result[] 要一直替換
 * 也就是 result[i] 與 result[i + 1] 要不同 groups[]
 */
class Solution {
  public:
   vector<string> getLongestSubsequence(vector<string>& words,
                                        vector<int>& groups) {
     vector<string> result;
     int size = words.size();
 
     result.push_back(words[0]);
     bool group = groups[0];
 
     for (int i = 1; i < size; i++) {
       if (group == groups[i]) continue;
 
       group = groups[i];
       result.push_back(words[i]);
     }
     return result;
   }
 };