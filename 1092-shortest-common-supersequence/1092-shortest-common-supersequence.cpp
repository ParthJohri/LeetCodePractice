class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int m=s.length(),n=t.length();
        vector<vector<string>> dp(m+1,vector<string>(n+1,""));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+s[i-1];
                else
                    dp[i][j]=dp[i-1][j].length()>dp[i][j-1].length()?dp[i-1][j]:dp[i][j-1];
            }
        }
        string lcs=dp[m][n];
        string ans="";
        int j=0,k=0;
        for(auto i:lcs)
        {
           while(s[j]!=i)
               ans+=s[j++];
            while(t[k]!=i)
                ans+=t[k++];
            ans+=i;
            j++;
            k++;
        }
        return ans+s.substr(j)+t.substr(k);
    }
};