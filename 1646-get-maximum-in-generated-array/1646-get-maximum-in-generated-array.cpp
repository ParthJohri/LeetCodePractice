class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> dp(n+2,0);
        dp[0]=0;
        dp[1]=1;
        int mx=0;
        for(int i=0;i<=n;i++){
            if(i%2==0)
                dp[i]=dp[i/2];
            else
                dp[i]=dp[i/2]+dp[i/2+1];
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};