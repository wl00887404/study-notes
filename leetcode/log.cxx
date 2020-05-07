#include <iostream>
#include <vector>
using namespace std;

string stringify(string& x) { return "\"" + x + "\""; }

string stringify(int& x) { return to_string(x); }

vector<string> stringify(vector<string> xs) {
  vector<string> results;

  for (string x : xs) results.push_back(stringify(x));

  return results;
}

vector<string> stringify(vector<int> xs) {
  vector<string> results;

  for (int x : xs) results.push_back(stringify(x));

  return results;
}

vector<vector<string>> stringify(vector<vector<string>> xss) {
  vector<vector<string>> resultss;

  for (vector<string> xs : xss) resultss.push_back(stringify(xs));

  return resultss;
}

vector<vector<string>> stringify(vector<vector<int>> xss) {
  vector<vector<string>> resultss;

  for (vector<int> xs : xss) resultss.push_back(stringify(xs));

  return resultss;
}

string toJSON(vector<string>& xs) {
  int length = xs.size();

  if (length == 0) return "[]";

  int totalLength = 0;

  for (string& x : xs) totalLength += x.size();

  string result = "[ ";

  int i = 0;
  for (; i < length - 1; i++) {
    result += xs[i] + ", ";

    if (totalLength > 39) result += "\n  ";
  }

  result += xs[i] + " ]";

  return result;
}

string toJSON(vector<vector<string>>& xss) {
  int length = xss.size();

  if (length == 0) return "[]";

  string result = "[\n";

  int i = 0;
  for (; i < length - 1; i++) {
    vector<string> xs = xss[i];

    result += "  " + toJSON(xs) + ",\n";
  }

  result += "  " + toJSON(xss[length - 1]) + "\n]";

  return result;
}

void log(vector<int>& xs) {
  vector<string> stringified = stringify(xs);

  cout << toJSON(stringified) << endl;
}

void log(vector<string>& xs) {
  vector<string> stringified = stringify(xs);

  cout << toJSON(stringified) << endl;
}

void log(vector<vector<int>>& xss) {
  vector<vector<string>> stringified = stringify(xss);

  cout << toJSON(stringified) << endl;
}

void log(vector<vector<string>>& xss) {
  vector<vector<string>> stringified = stringify(xss);

  cout << toJSON(stringified) << endl;
}