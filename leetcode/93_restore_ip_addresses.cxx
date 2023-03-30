#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * 先 parse 一組數字
 * 長度必須 1 ~ 3
 * 1 個數字全通過
 * 2 個數字全通過
 * 3 個數字必須小於 255
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        sPointer = &s;
        length = s.size();
        if(length < 4 || length > 12) return {};

        parsed.resize(length);

        queue<string> q;
        vector<string> result;

        parse(0);
        for(string& s: parsed[0]){
            q.push(s);
        }
        
        for(int i = 0; i < 3;i++ ){
            int size = q.size();

            while(size--){
                string& current = q.front();
                int onlyDigitalLength = current.length() - i;
                if(onlyDigitalLength < length) {
                    parse(onlyDigitalLength);
                    for(string& next: parsed[onlyDigitalLength]){
                        q.push(current+ "." + next);
                    }
                }

                q.pop();
            }
        }

        while(!q.empty()){
            if(q.front().length() == length + 3){
                result.push_back(q.front());
            }
            q.pop();
        }

        return result;
    }

    string* sPointer;
    int length;
    vector<vector<string>> parsed;

    void parse(int i) {
        if(i >= length) return;
        if(parsed[i].size() != 0) return;
        
        string& s = *sPointer;
        string sliced = "";
        
        sliced += s[i];
        parsed[i].push_back(sliced);

        // 不能開頭 0
        if(s[i] == '0' || i + 1 >= length) return;
        
        sliced += s[i + 1];
        parsed[i].push_back(sliced);
        
        if(i + 2 >= length) return;
        
        sliced += s[i + 2];
        if(stoi(sliced) > 255) return;
        
        parsed[i].push_back(sliced);
    }
};