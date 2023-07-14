class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            dp[i][i+1]=s[i]==s[i+1];
        }
        for(int len = 2;len <= n-1;len++){
            for(int i=0;i<n-len;i++){
                dp[i][i+len] = s[i]==s[i+len] and dp[i+1][i+len-1];
            }
        }
        int index=0,len=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]==1 and len<(j-i+1)) {
                    index=i,len=j-i+1;
                }
            }
        }
        ans=s.substr(index,len);
        return ans;
    }
};