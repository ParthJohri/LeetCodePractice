class Solution {
public:
    int mod=1e9+7;
    map<long long int,map<long long int,long long int>> dp;
    long long int recur(int s,int l,int i){
        if(i>=l or i<0 or s<0) return 0;
        if(s==0) return i==0;
        if(dp[i].count(s)) return dp[i][s];
        long long int a=recur(s-1,l,i-1)%mod;
        long long int b=recur(s-1,l,i+1)%mod;
        long long int c=recur(s-1,l,i)%mod;
        return dp[i][s]=(a%mod+b%mod+c%mod)%mod;
    }
    int numWays(int steps, int arrLen) {
        return recur(steps,arrLen,0)%mod;
    }
};