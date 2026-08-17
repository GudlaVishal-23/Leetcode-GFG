#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
    int memo[501][501];
    
    int solve(int left, int right, const vector<int>& prefixSum) {
        // Base case: If only one stone remains, no more splits can be made.
        if (left == right) {
            return 0;
        }
        
        // Return cached result if already computed
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        
        int maxScore = 0;
        
        // Iterate through all possible split points between left and right index
        for (int mid = left; mid < right; ++mid) {
            // Calculate sum of left subarray in O(1) time
            int leftSum = prefixSum[mid + 1] - prefixSum[left];
            // Calculate sum of right subarray in O(1) time
            int rightSum = prefixSum[right + 1] - prefixSum[mid + 1];
            
            if (leftSum < rightSum) {
                // Bob discards the larger right subarray
                maxScore = max(maxScore, leftSum + solve(left, mid, prefixSum));
            } 
            else if (leftSum > rightSum) {
                // Bob discards the larger left subarray
                maxScore = max(maxScore, rightSum + solve(mid + 1, right, prefixSum));
            } 
            else {
                // If equal, Alice chooses which one to keep to maximize score
                int keepLeft = leftSum + solve(left, mid, prefixSum);
                int keepRight = rightSum + solve(mid + 1, right, prefixSum);
                maxScore = max({maxScore, keepLeft, keepRight});
            }
        }
        
        return memo[left][right] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));
        
        // Build prefix sum array to retrieve subarray sums in O(1) time
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + stoneValue[i];
        }
        
        return solve(0, n - 1, prefixSum);
    }
};
