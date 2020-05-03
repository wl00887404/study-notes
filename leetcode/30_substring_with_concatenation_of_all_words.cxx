#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "./log.cxx"
using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int sLength = s.size();
    int wordsLength = words.size();

    if (sLength == 0 || wordsLength == 0) return {};

    int wordLength = words[0].size();

    unordered_map<string, int> frequencyMap;
    unordered_map<int, string*> matchMap;
    vector<int> matchIndexies;
    int limit = sLength - wordLength * wordsLength;

    for (string& word : words) {
      frequencyMap[word]++;

      if (frequencyMap[word] > 1) continue;

      for (int i = 0; i < sLength; i++) {
        int j = 0;

        while (j < wordLength && s[i + j] == word[j]) j++;

        if (j == wordLength) {
          matchMap[i] = &word;
          if (i <= limit) matchIndexies.push_back(i);
        }
      }
    }

    unordered_map<string, int> used;
    vector<int> results;

    for (int& begin : matchIndexies) {
      used.clear();

      int i = 0;
      for (; i < wordsLength; i++) {
        int index = begin + wordLength * i;

        if (!matchMap.count(index)) break;
        if (index >= sLength) break;

        used[*matchMap[index]]++;

        if (used[*matchMap[index]] > frequencyMap[*matchMap[index]]) break;
      }

      if (i == wordsLength) results.push_back(begin);
    }

    return results;
  };

} solution;

int main() {
  // string s = "barfoothefoobarman";
  // vector<string> words = {"foo", "bar"};

  // string s = "wordgoodgoodgoodbestword";
  // vector<string> words = {"word", "good", "best", "word"};

  string s = "wordgoodgoodgoodbestword";
  vector<string> words = {"word", "good", "best", "good"};

  // string s =
  //     "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmy"
  //     "xgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoa"
  //     "dfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjyctt"
  //     "prkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwa"
  //     "jrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhduce"
  //     "sctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtrax"
  //     "rlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabe"
  //     "jifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtq"
  //     "kscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyr"
  //     "dtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkp"
  //     "uuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjh"
  //     "zadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrow"
  //     "zljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrd"
  //     "hvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbz"
  //     "vaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhv"
  //     "akcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztk"
  //     "cbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzec"
  //     "bgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvo"
  //     "pddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqs"
  //     "qahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjek"
  //     "ystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeix"
  //     "kdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfi"
  //     "dgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztk"
  //     "rzwrpabqrrhnlerxjojemcxel";
  // vector<string> words = {"dhvf", "sind", "ffsl", "yekr", "zwzq", "kpeo",
  //                         "cila", "tfty", "modg", "ztjg", "ybty", "heqg",
  //                         "cpwo", "gdcj", "lnle", "sefg", "vimw", "bxcb"};

  vector<int> results = solution.findSubstring(s, words);

  log(results);

  return 0;
}