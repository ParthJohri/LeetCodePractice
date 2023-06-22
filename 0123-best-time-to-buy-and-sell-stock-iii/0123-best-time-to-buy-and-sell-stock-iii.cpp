class Solution {
public:
    int recur(vector<int>&prices,int index,int k,bool flag,vector<vector<vector<int>>>&dp){
        if(index>=prices.size() or k==0) return 0;
        if(dp[index][flag][k]!=-1) return dp[index][flag][k];
        int profit=0;
        if(flag){
            int buy=recur(prices,index+1,k,false,dp)-prices[index];
            int notbuy=recur(prices,index+1,k,true,dp);
            profit=max({profit,buy,notbuy});
        }
        else{
            int sell=prices[index]+recur(prices,index+1,k-1,true,dp);
            int notsell=recur(prices,index+1,k,false,dp);
            profit=max({profit,sell,notsell});
        }
        return dp[index][flag][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int k=2,n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return recur(prices,0,2,true,dp);
    }
};