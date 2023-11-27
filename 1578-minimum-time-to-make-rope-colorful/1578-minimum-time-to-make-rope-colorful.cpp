class Solution {
public:
    long long int dp[100001];
    long long int recur(int i,string&c, vector<int>&n){
        if(i>=c.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        long long int ans=INT_MAX;
        if(c[i]==c[i+1]){
            if(n[i]>n[i+1]) swap(n[i],n[i+1]);
            ans=min(n[i],n[i+1])+recur(i+1,c,n);
        }
        else ans=recur(i+1,c,n);
        return dp[i]=ans;
    }
    int minCost(string colors, vector<int>& neededTime) {
        memset(dp,-1,sizeof(dp));
        return recur(0,colors,neededTime);
    }
};