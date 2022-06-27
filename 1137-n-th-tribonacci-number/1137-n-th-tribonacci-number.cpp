class Solution {
public:
    int fib(vector<int> &dp,int n) {
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        if(dp[n]!=0) return dp[n];
        dp[n]=fib(dp,n-1)+fib(dp,n-2)+fib(dp,n-3);
        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+5,0);
        return fib(dp,n); // Recusive DP With Memoization
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        dp[4]=4;
        for(int i=5;i<=n;i++) // Iterative DP With Memoization
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        return dp[n];
    }
};