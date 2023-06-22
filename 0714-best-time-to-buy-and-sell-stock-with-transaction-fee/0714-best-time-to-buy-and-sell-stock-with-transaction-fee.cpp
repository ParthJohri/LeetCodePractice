class Solution {
public:
    int recur(vector<int>&prices,int index,int flag,int fees,vector<vector<int>>&dp){
        if(index>=prices.size()) return 0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        int ans=0;
        if(flag){
            int buy=recur(prices,index+1,false,fees,dp)-prices[index]-fees;
            int notbuy=recur(prices,index+1,true,fees,dp);
            ans=max({ans,buy,notbuy});
        }
        else{
            int sell=prices[index]+recur(prices,index+1,true,fees,dp);
            int notsell=recur(prices,index+1,false,fees,dp);
            ans=max({ans,sell,notsell});
        }
        return dp[index][flag]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int maxP=recur(prices,0,true,fee,dp);
        return maxP;
    }
};