class Solution {
public:
    int ans(string& a, string& b, int& n, int& m, int i, int j,vector<vector<int>>&dp){
        if(i>=n or j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int an=0;
        if(a[i]==b[j]) an=1+ans(a,b,n,m,i+1,j+1,dp);
        return dp[i][j]=max({an, ans(a,b,n,m,i+1,j,dp), ans(a,b,n,m,i,j+1,dp)});
     }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        ans(text1,text2,n,m,0,0,dp);
        return dp[0][0];
    }
};