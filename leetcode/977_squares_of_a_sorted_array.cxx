class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int i = right;
        vector<int> result(nums.size());

        while (i >= 0) {
            int& m = nums[left];
            int& n = nums[right];

            if (m * m > n * n) {
                result[i] = m * m;
                left++;
            } else {
                result[i] = n * n;
                right--;
            }

            i--;
        }

        return result;
    }
};
