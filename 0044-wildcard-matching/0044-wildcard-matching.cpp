class Solution {
public:
    bool recur(string& p,string& s,int i,int j,vector<vector<int>>&dp){
        int m=p.length(),n=s.length();
        if(i==m and j==n) return true;
        if(i>=m) return false;
        // ab 
        // ab**
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==n and i!=m){
            while(i<m){
                if(p[i++]!='*') return false;
            }
            return true;
        }
        bool check=false;
        if(s[j]==p[i] or p[i]=='?'){
           check = recur(p,s,i+1,j+1,dp);
        }
        else if(p[i]=='*'){
           check = recur(p,s,i,j+1,dp) or recur(p,s,i+1,j,dp);
        }
        return dp[i][j]=check;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.length()+1,vector<int>(s.length()+1,-1));
        return recur(p,s,0,0,dp);
    }
};