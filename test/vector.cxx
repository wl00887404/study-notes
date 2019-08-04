#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // vector<int> vec(5, 0);

  // vec.insert(vec.end(), 1);
  // vec.push_back(2);

  // for (int i = 0; i < vec.size(); i++)
  // {
  //   cout << vec[i] << endl;
  // }

  vector<int> vec = {0, 1, 2, 3, 4};

  vector<int>::iterator begin = vec.begin();
  while (begin != vec.end())
  {
    cout << *begin << endl;
    begin++;
  }

  return 0;
}
