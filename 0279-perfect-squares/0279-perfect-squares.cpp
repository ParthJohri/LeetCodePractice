class Solution
{
    private:
        long long int dp[100000];
    vector<int> ps;
    public:
        long long int recur(int n)
        {
            if (n<=0) return 0;
            if (dp[n] != -1) return dp[n];
            long long int ans=LLONG_MAX;
            for(int i=1;i*i<=n;i++){
                if(n-(i*i)>=0){
                    ans=min(ans,1+recur(n-i*i));
                }
            }
            return dp[n] = ans;
        }
    int numSquares(int n)
    {
        memset(dp, INT_MAX, sizeof(dp));
        // return recur(n);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            long long int mn=INT_MAX;
            for(int j=1;j*j<=i;j++){
                long long int sq=j*j;
                mn=min(mn,1+dp[i-sq]);
            }
            dp[i]=mn;
        }
        return dp[n];
    }
};