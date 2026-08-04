class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = 0; i < nums.size() - 1; i++) {
            // Skip duplicate elements
            if (nums[i] == nums[i + 1])
                continue;

            // Add all missing numbers between consecutive elements
            for (int x = nums[i] + 1; x < nums[i + 1]; x++) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};