#include <iostream>
#include <vector>
using namespace std;

string stringify(vector<string>& xs) {
  int length = xs.size();

  if (length == 0) return "[]";

  int totalLength = 0;

  for (string x : xs) totalLength += x.size();

  string result = "";

  result = "[ ";
  int i = 0;

  for (; i < length - 1; i++) {
    result += xs[i] + ", ";

    if (totalLength > 39) result += "\n  ";
  }

  result += xs[i] + " ]";

  return result;
}

vector<string> toString(vector<int>& xs) {
  vector<string> results;

  for (int x : xs) {
    results.push_back(to_string(x));
  }

  return results;
}

string stringify(vector<int>& xs) {
  vector<string> stringified = toString(xs);

  return stringify(stringified);
}

string stringify(vector<vector<int>>& xss) {
  if (xss.size() == 0) return "[]";

  string result = "[\n";

  for (vector<int> xs : xss) {
    vector<string> stringified = toString(xs);
    result += "  " + stringify(stringified) + ",\n";
  }

  result += "]";

  return result;
}

void log(vector<int>& xs) { cout << stringify(xs) << endl; }
void log(vector<string>& xs) { cout << stringify(xs) << endl; }
void log(vector<vector<int>>& xss) { cout << stringify(xss) << endl; }