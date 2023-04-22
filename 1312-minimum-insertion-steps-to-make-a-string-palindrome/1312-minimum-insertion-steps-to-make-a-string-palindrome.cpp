class Solution {
public:
    int dp[501][501];
    int recur(string& s,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=recur(s,i+1,j-1);
        else return dp[i][j]=1+min(recur(s,i+1,j),recur(s,i,j-1));
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return recur(s,0,s.length()-1);
    }
};