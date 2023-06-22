class Solution {
public:
    int profit(vector<int>&prices,int index,bool flag,int k,vector<vector<vector<int>>>&dp){
        if(index>=prices.size() or k==0) return 0;
        if(dp[index][flag][k]!=-1) return dp[index][flag][k];
        int ans=0;
        if(flag){
            int buy=profit(prices,index+1,false,k,dp)-prices[index];
            int notbuy=profit(prices,index+1,true,k,dp);
            ans=max({ans,buy,notbuy});
        }
        else{
            int sell=prices[index]+profit(prices,index+1,true,k-1,dp);
            int notsell=profit(prices,index+1,false,k,dp);
            ans=max({ans,sell,notsell});
        }
        return dp[index][flag][k]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return profit(prices,0,true,k,dp);
    }
};