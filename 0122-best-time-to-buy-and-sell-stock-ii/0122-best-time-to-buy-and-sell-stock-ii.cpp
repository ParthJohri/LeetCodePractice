class Solution {
public:
    int recur(int n, vector<int>& prices,vector<int>&dp){
        if(n>=prices.size()-1) return 0;
        if(dp[n]!=-1) return dp[n];
        int buyit=0,notbuyit=0;
        notbuyit=recur(n+1,prices,dp);
        if(prices[n+1]>prices[n]){
             buyit=prices[n+1]-prices[n]+recur(n+1,prices,dp);
        }
        return dp[n]=max(buyit,notbuyit);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1) return 0;
        vector<int> dp(n+1,-1);
        recur(0,prices,dp);
        return dp[0];
    }
};