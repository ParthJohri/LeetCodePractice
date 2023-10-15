class Solution {
public:
    unordered_map<int,unordered_map<int,int>> dp;
    int mod=1e9+7;
    int recur(int k,int t, int i){
        if(k<0  or (abs(i)+k)<abs(t)) return 0;
        if(k==0) return i==t;
        if(dp[i].count(k)) return dp[i][k];
        int a=recur(k-1,t,i+1)%mod;
        int b=recur(k-1,t,i-1)%mod;
        return dp[i][k]=(a%mod+b%mod)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        return recur(k,endPos,startPos)%mod;
    }
};