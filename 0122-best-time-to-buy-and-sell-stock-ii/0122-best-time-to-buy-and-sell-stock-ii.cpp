class Solution {
public:
    int recur(int n, vector<int>& prices,vector<vector<int>>&dp,int s){
        if(n>=prices.size()) return 0;
        if(dp[n][s]!=-1) return dp[n][s];
        int ans=0;
        if(s==0) ans=max(recur(n+1,prices,dp,s),-prices[n]+recur(n+1,prices,dp,s+1));
        else if(s==1) ans=max(recur(n+1,prices,dp,s),+prices[n]+recur(n+1,prices,dp,s-1));
        // int buyit=0,notbuyit=0;
        // notbuyit=
        // if(prices[n+1]>prices[n]){
        //      buyit=prices[n+1]-prices[n]+recur(n+1,prices,dp,s);
        // }
        return dp[n][s]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),s=0;
        if(n==1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // dp[i][1] - stock in hand
        // dp[i][0] -  stock not in hand
        return recur(0,prices,dp,s);
    }
};