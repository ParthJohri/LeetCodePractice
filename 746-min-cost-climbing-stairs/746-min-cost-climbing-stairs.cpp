class Solution {
public:
    int dp[1002];
    int mn(vector<int> c,int x)
    {
        if(x>=c.size())
        return 0;
        if(dp[x]!=-1) return dp[x];
        dp[x]=c[x]+min(mn(c,x+1),mn(c,x+2));
        return dp[x];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int m1=mn(cost,0);
        int m2=mn(cost,1);
        return min(m1,m2);
    }
};