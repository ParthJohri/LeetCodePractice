class Solution {
public:
    // int dp[10000]={0};
    int climbStairs(int n) {
        // if(n<=2) return n;
        // if(dp[n]!=0) return dp[n];
        // return dp[n]=climbStairs(n-1)+climbStairs(n-2);
        int dp[n+10];
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};