class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // vector storing {value, index}
        vector<pair<int, int>> arr(n);

        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }

        // sort the vector based on value
        sort(arr.begin(), arr.end());

        // vector to store indices fron the sorted arr
        vector<int> indices(n);

        for(int i = 0; i < n; i++) {
            indices[i] = arr[i].second;
        }

        int l = 0;

        // sort the indices for each group
        for(int i = 1; i < n; i++) {
            if(arr[i].first - arr[i-1].first > limit) {
                sort(indices.begin() + l, indices.begin() + i);
                l = i;
            }
        }
        sort(indices.begin() + l, indices.end());

        vector<int> answer(n);

        // form the answer vector using lowest index-vaue for each group
        for(int i = 0; i < n; i++) {
            answer[indices[i]] = arr[i].first;
        }

        return answer;
    }
};