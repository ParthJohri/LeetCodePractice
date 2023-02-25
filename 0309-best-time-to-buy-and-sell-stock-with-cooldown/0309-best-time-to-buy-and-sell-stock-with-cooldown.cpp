class Solution {
public:
    int recur(int n,vector<int>&prices,vector<vector<int>>&dp,int s){
        if(n>=prices.size()) return 0;
        if(dp[n][s]!=-1) return dp[n][s];
        int ans=0;
        if(s==0){
            ans=max(recur(n+1,prices,dp,s),-prices[n]+recur(n+1,prices,dp,s+1));
        }
        else if(s==1){
            ans=max(recur(n+1,prices,dp,s),+prices[n]+recur(n+2,prices,dp,s-1));
        }
        return dp[n][s]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),s=0;
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return recur(0,prices,dp,s);
    }
};