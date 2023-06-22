class Solution {
public:
    int recur(vector<int>&prices,int index,int flag,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        int profit=0;
        if(flag){
            int buy=recur(prices,index+1,false,dp)-prices[index];
            // recur gives the value at which the stock is sold
            int notbuy=recur(prices,index+1,true,dp);
            profit=max({profit,buy,notbuy});
        }
        else{
            int sell=prices[index]+recur(prices,index+1,true,dp);
            int notsell=recur(prices,index+1,false,dp);
            profit=max({profit,sell,notsell});
        }
        return dp[index][flag]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return recur(prices,0,true,dp);
    }
};