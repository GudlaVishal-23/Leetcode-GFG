class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorValue = 0;

        for (int x : nums)
            xorValue ^= x;

        if (xorValue != 0)
            return nums.size();

        for (int x : nums)
            if (x != 0)
                return nums.size() - 1;

        return 0;
    }
};