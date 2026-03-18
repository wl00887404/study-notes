#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    unordered_map<char, int> coefficientMap;
    unordered_set<char> beginChars;
    unordered_set<char> charsSet;
    vector<bool> usedNums;
    vector<char> chars;

    bool isSolvable(vector<string>& words, string result) {
        for (string& word : words) {
            parse(word, 1);
        }
        parse(result, -1);

        // 係數是 0 的字元，不用處理
        for (auto c : charsSet) {
            if (coefficientMap[c] != 0) {
                chars.push_back(c);
            }
        }

        if (chars.size() > 10) {
            return false;
        }

        usedNums.resize(10, false);

        return helper(0);
    }

    void parse(string& word, int sign = 1) {
        // 只有一個字母，不能算是 leading 0
        if (word.size() > 1) {
            beginChars.insert(word[0]);
        }

        int i = word.size();
        int amount = sign;

        while (i--) {
            charsSet.insert(word[i]);
            coefficientMap[word[i]] += amount;
            amount *= 10;
        }
    }

    int sum = 0;
    bool helper(int i) {
        char& c = chars[i];
        int& coefficient = coefficientMap[c];
        int lowerLimit = beginChars.count(c) ? 1 : 0;

        if (i == chars.size() - 1) {
            // sum + coefficient * v = 0
            // v = - sum / coefficient

            // sum 與 coefficient 必須一正一負
            if ((sum > 0 && coefficient > 0) || (sum < 0 && coefficient < 0)) {
                return false;
            }

            int postiveSum = abs(sum);
            int postiveCoefficient = abs(coefficient);
            if (postiveSum % postiveCoefficient != 0) {
                return false;
            }
            int v = postiveSum / postiveCoefficient;

            return lowerLimit <= v && v <= 9 && usedNums[v] == false;
        }

        for (int v = lowerLimit; v <= 9; v++) {
            if (usedNums[v]) {
                continue;
            }
            usedNums[v] = true;
            sum += coefficient * v;
            if (helper(i + 1)) {
                return true;
            }
            sum -= coefficient * v;
            usedNums[v] = false;
        }

        return false;
    }
};