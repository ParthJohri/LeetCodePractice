class Solution {
public:
    // int dp[10000]={0};
    int climbStairs(int n) {
        // if(n<=2) return n;
        // if(dp[n]!=0) return dp[n];
        // return dp[n]=climbStairs(n-1)+climbStairs(n-2);
        int step1=0,step2=1,ans=0;
        for(int i=1;i<=n;i++){
            ans=step1+step2;
            step1=step2;
            step2=ans;
        }
        return ans;
    }
};