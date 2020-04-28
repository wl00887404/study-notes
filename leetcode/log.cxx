#include <iostream>
#include <vector>
using namespace std;

string stringify(vector<string>& xs, int indentation = 0) {
  int length = xs.size();

  if (length == 0) return "[]";

  int totalLength = 0;

  for (string x : xs) totalLength += x.size();

  string result = "";

  for (int i = 0; i < indentation; i++) result += " ";

  result = "[ ";
  int i = 0;

  for (; i < length - 1; i++) {
    for (int j = 0; j < indentation; j++) result += " ";

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

string stringify(vector<int>& xs, int indentation = 0) {
  vector<string> stringified = toString(xs);

  return stringify(stringified, indentation);
}

void log(vector<int>& xs) { cout << stringify(xs) << endl; }
void log(vector<string>& xs) { cout << stringify(xs) << endl; }