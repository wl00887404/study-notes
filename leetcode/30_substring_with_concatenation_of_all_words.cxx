#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "./log.cxx"
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  bool isWord;
  TrieNode() : isWord(false) {}
};

class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int sLength = s.size();
    int wordsLength = words.size();

    if (sLength == 0 || wordsLength == 0) return {};

    int wordLength = words[0].size();

    TrieNode* root = buildTrie(words, wordsLength, wordLength);
    vector<int> results;

    for (int i = 0; i < sLength; i++) {
      TrieNode* p = root;
      int j = i;

      while (true) {
        if (!p->children.count(s[j])) break;

        p = p->children[s[j]];
        j++;
      }

      if (p->isWord) results.push_back(i);
    }

    return results;
  };

 private:
  TrieNode* buildTrie(vector<string>& words, int& wordsLength,
                      int& wordLength) {
    TrieNode* root = new TrieNode();

    buildTrie(root, wordsLength, wordLength, words, wordsLength);

    return root;
  }

  void buildTrie(TrieNode* root, int& wordsLength, int& wordLength,
                 vector<string>& words, int k) {
    if (k == 1) {
      TrieNode* p = root;

      for (int i = 0; i < wordsLength; i++) {
        for (int j = 0; j < wordLength; j++) {
          if (!p->children.count(words[i][j])) {
            p->children[words[i][j]] = new TrieNode();
          }

          p = p->children[words[i][j]];
        }
      }
      p->isWord = true;
      return;
    }

    unordered_set<string> used;

    buildTrie(root, wordsLength, wordLength, words, k - 1);
    used.insert(words[k - 1]);

    for (int i = 0; i < k - 1; i++) {
      if (used.count(words[i])) continue;

      swap(words[i], words[k - 1]);
      used.insert(words[k - 1]);
      buildTrie(root, wordsLength, wordLength, words, k - 1);
      swap(words[i], words[k - 1]);
    }
  }
} solution;

int main() {
  string s = "barfoothefoobarman";
  vector<string> words = {"foo", "bar"};

  // string s = "wordgoodgoodgoodbestword";
  // vector<string> words = {"word", "good", "best", "word"};

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