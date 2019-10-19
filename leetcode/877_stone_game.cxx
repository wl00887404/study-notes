#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool stoneGame(vector<int> &piles)
  {
    int alex = 0;
    int lee = 0;
    int cost1;
    int cost2;

    int i = 0;
    int j = piles.size() - 1;

    while (i != j)
    {
      cout << "alex: " << piles[i] << " vs " << piles[j] << endl;
      cost1 = piles[i] - max(piles[i + 1], piles[j]);
      cout << piles[i] << " 的成本為 " << max(piles[i + 1], piles[j]) << " | " << cost1 << endl;
      cost2 = piles[j] - max(piles[j - 1], piles[i]);
      cout << piles[j] << " 的成本為 " << max(piles[j - 1], piles[i]) << " | " << cost2 << endl;

      if (cost1 == cost2)
      {
        cout << "成本一樣是三小啦幹幹幹幹幹" << endl;
        int leftCost1 = piles[i + 1] - max(piles[i + 2], piles[j]);
        int leftCost2 = piles[j] - max(piles[i + 1], piles[j]);
        int rightCost1 = piles[i] - max(piles[i + 1], piles[j - 1]);
        int rightCost2 = piles[j - 1] - max(piles[i], piles[j - 2]);
        cout << "選左邊 " << piles[i] << endl;
        cout << piles[i + 1] << " 的成本為 " << leftCost1 << endl;
        cout << piles[j] << " 的成本為 " << leftCost2 << endl;
        cout << "選右邊 " << piles[j] << endl;
        cout << piles[i] << " 的成本為 " << rightCost1 << endl;
        cout << piles[j - 1] << " 的成本為 " << rightCost2 << endl;

        cost1 = max(leftCost1, leftCost2) * -1;
        cost2 = max(rightCost1, rightCost2) * -1;
      }

      if (cost1 > cost2)
      {
        cout << "取 " << piles[i] << endl
             << endl;
        alex += piles[i];
        i++;
      }
      else
      {
        cout << "取 " << piles[j] << endl
             << endl;
        alex += piles[j];
        j--;
      }

      if (i == j)
      {
        lee += piles[i];
        break;
      }

      cout << "lee: " << piles[i] << " vs " << piles[j] << endl;
      cost1 = piles[i] - max(piles[i + 1], piles[j]);
      cout << piles[i] << " 的成本為 " << max(piles[i + 1], piles[j]) << " | " << cost1 << endl;
      cost2 = piles[j] - max(piles[j - 1], piles[i]);
      cout << piles[j] << " 的成本為 " << max(piles[j - 1], piles[i]) << " | " << cost2 << endl;

      if (cost1 == cost2)
      {
        cout << "成本一樣是三小啦幹幹幹幹幹" << endl;
        int leftCost1 = piles[i + 1] - max(piles[i + 2], piles[j]);
        int leftCost2 = piles[j] - max(piles[i + 1], piles[j]);
        int rightCost1 = piles[i] - max(piles[i + 1], piles[j - 1]);
        int rightCost2 = piles[j - 1] - max(piles[i], piles[j - 2]);
        cout << "選左邊 " << piles[i] << endl;
        cout << piles[i + 1] << " 的成本為 " << leftCost1 << endl;
        cout << piles[j] << " 的成本為 " << leftCost2 << endl;
        cout << "選右邊 " << piles[j] << endl;
        cout << piles[i] << " 的成本為 " << rightCost1 << endl;
        cout << piles[j - 1] << " 的成本為 " << rightCost2 << endl;

        cost1 = max(leftCost1, leftCost2) * -1;
        cost2 = max(rightCost1, rightCost2) * -1;
      }

      if (cost1 > cost2)
      {
        lee += piles[i];
        cout << "取 " << piles[i] << endl
             << endl;
        i++;
      }
      else
      {
        cout << "取 " << piles[j] << endl
             << endl;
        lee += piles[j];
        j--;
      }
    }

    cout << "alex: " << alex << endl;
    cout << "lee: " << lee << endl;

    return alex > lee;
  }

} solution;

int main()
{
  // vector<int> v1 = {5, 3, 4, 5};
  // vector<int> v2 = {6, 8, 4, 5};
  // vector<int> v3 = {1, 4, 10, 8, 3, 2, 4, 1};
  // vector<int> v4 = {6, 3, 9, 9, 3, 8, 8, 7};
  vector<int> v5 = {3, 7, 3, 2, 5, 1, 6, 3, 10, 7};

  cout << solution.stoneGame(v5) << endl;

  return 0;
}