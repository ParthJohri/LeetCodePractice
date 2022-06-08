class Solution {
public:
    int dp[46];
    int stairs(int n)
    {
        if(n==0||n==1)
        return 0;
        if(dp[n]!=0) return dp[n];
        dp[n]=1+stairs(n-1)+stairs(n-2);
        return dp[n];
    }
    int climbStairs(int n) {
        return stairs(n)+1;
    }
};