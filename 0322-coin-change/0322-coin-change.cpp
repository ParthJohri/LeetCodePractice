class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<amount+1;i++)
        {
            for(auto c:coins)
            {
                if(i-c>=0)
                {
                    // if(dp[i-c]!=INT_MAX)
                    dp[i]=min(dp[i-c]+1,dp[i]);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};