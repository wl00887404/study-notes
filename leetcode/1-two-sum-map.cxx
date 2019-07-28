#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
      map[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++)
    {
      int left = target - nums[i];
      if (map.count(left) && map[left] != i)
      {
        return {i, map[left]};
      }
    }

    return {};
  }
};