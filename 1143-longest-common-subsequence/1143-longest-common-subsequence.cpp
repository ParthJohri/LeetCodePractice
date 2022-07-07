class Solution {
public:
    int longCommonSub(string &s,string &t,int m,int n, vector<vector<int>> &dp) {
        // Recursive Solution : No Memo - TLE O(2^N)
        // Recurive Solution With Memo : O(M*N)
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
        // return longCommonSub(s,t,m,n,dp);
        // Iterative Tabulation : O(M*N) Faster than Recursive solution With Memo because of Function Calls in the Stack
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};