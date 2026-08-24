constexpr int N=1e5;
// dp[i]=max(Alice's score-Bob's score 
// up to ith stone taken by Alice in 1st turn)
int dp[N]={0};
class Solution {
public:
    static int stoneGameVIII(vector<int>& stones) {
        const int n=stones.size();
        partial_sum(stones.begin(), stones.end(), stones.begin());
        dp[n-1]=stones.back();
        for(int i=n-2; i>=1; i--){
            dp[i]=max(dp[i+1], stones[i]-dp[i+1]);
        }
        return dp[1];
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();