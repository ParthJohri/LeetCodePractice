class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+5,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        dp[4]=3;
        for(int i=5;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};