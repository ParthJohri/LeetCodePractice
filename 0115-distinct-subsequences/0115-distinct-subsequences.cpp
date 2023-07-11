class Solution {
public:
    int dp[1007][1007];
    int recur(string& s,int index,string& t,int idx){
        if(idx==t.length()) return 1;
        if(index==s.length()) return 0;
        if(dp[index][idx]!=-1) return dp[index][idx];
        int ans=0;
        if(s[index]==t[idx]) ans=recur(s,index+1,t,idx+1)+recur(s,index+1,t,idx);
        else ans=recur(s,index+1,t,idx);
        return dp[index][idx]=ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return recur(s,0,t,0);
    }
};