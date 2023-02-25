class Solution {
public:
    int recur(int n, vector<int>& prices,vector<vector<vector<int>>>&dp,int s,int count,int k){
        if(n>=prices.size()) return 0;
        if(dp[n][s][count]!=-1) return dp[n][s][count];
        int ans=0;
        if(s==0) {
            if(count==k){
                ans=recur(n+1,prices,dp,s,count,k);
            }
            else{
                ans=max(recur(n+1,prices,dp,s,count,k),-prices[n]+recur(n+1,prices,dp,s+1,count,k));
            }
        }
        else if(s==1) {
            if(count==k){
                ans=recur(n+1,prices,dp,s,count,k);
            }
            else{
                ans=max(recur(n+1,prices,dp,s,count,k),+prices[n]+recur(n+1,prices,dp,s-1,count+1,k));
            }
        }
        return dp[n][s][count]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size(),s=0,count=0;
        if(n==1) return 0;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // dp[i][1] - stock in hand
        // dp[i][0] -  stock not in hand
        return recur(0,prices,dp,s,count,k);
    }
};