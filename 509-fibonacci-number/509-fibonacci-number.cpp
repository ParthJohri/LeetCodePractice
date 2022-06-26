class Solution {
private:
    int dp[31]={0};
public:
    int fib(int n) {
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