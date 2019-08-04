#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> vec(5, 0);

  vec.insert(vec.end(), 1);
  vec.push_back(2);

  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << endl;
  }

  return 0;
}
