class Solution {
private:
    int dp[46]={0};
public:
    int climbStairs(int n) {
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        dp[4]=5;
        for(int i=5;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};