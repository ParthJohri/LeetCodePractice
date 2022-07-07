class Solution {
public:
    int longCommonSub(string &s,string &t,int m,int n, vector<vector<int>> &dp) {
        if(m==0||n==0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(s[m-1]==t[n-1])
            dp[m][n]=1+longCommonSub(s,t,m-1,n-1,dp);
        else
            dp[m][n]=max(longCommonSub(s,t,m-1,n,dp),longCommonSub(s,t,m,n-1,dp));
        return dp[m][n];
    }
    int longestCommonSubsequence(string s, string t) {
        int m=s.length(),n=t.length();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return longCommonSub(s,t,m,n,dp);
    }
};