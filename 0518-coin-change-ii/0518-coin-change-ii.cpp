class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+10,vector<int>(amount+10,-1));
        function<int(int,int)> ans=[&](int index,int amount){
            if(amount==0) return 1;
            if(index==n or amount<0) return 0;
            if(dp[index][amount]!=-1) return dp[index][amount];
            int curr=0;
            if(coins[index]>amount) curr=ans(index+1,amount);
            else curr=ans(index,amount-coins[index])+ans(index+1,amount);
            return dp[index][amount]=curr;
        };
        return ans(0,amount);
    }
};