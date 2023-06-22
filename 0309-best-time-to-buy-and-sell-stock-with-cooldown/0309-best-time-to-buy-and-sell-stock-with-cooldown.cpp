class Solution {
public:
    int profit(vector<int>&prices,int index,bool flag,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        int totalprofit=0;
        if(flag)//to buy the stock
        {
            int buy=profit(prices,index+1,false,dp)-prices[index];
            int notbuy=profit(prices,index+1,true,dp);
            totalprofit=max({totalprofit,buy,notbuy});
        }
        else// to sell the stock
        {
            int sell=prices[index]+profit(prices,index+2,true,dp);// 1 extra day for cool down
            int notsell=profit(prices,index+1,false,dp);
            totalprofit=max({totalprofit,sell,notsell});
        }
        return dp[index][flag]=totalprofit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return profit(prices,0,true,dp);
    }
};