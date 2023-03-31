class Solution {
public:
    int mod=1e9+7;
    int dfs(int m,int n, int k,int r, int c,vector<vector<vector<int>>>&dp,vector<vector<int>>&prsum){
        if(prsum[r][c]==0) return 0;
        if(k==0) return 1;
        if(dp[k][r][c]!=-1) return dp[k][r][c];
        int ans=0;
        for(int nr=r+1;nr<m;nr++){
            if(prsum[r][c]-prsum[nr][c]>0)
                ans=(ans+dfs(m,n,k-1,nr,c,dp,prsum))%mod;
        }
        for(int nc=c+1;nc<n;nc++){
            if(prsum[r][c]-prsum[r][nc]>0)
                ans=(ans+dfs(m,n,k-1,r,nc,dp,prsum))%mod;
        }
        return dp[k][r][c]=ans;
    }
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size(),n=pizza[0].size();
        vector<vector<vector<int>>> dp(vector(k,vector(m,vector(n,-1))));
        vector<vector<int>> prsum(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                prsum[i][j]=prsum[i+1][j]+prsum[i][j+1]-prsum[i+1][j+1]+(pizza[i][j]=='A');
            }
        }
        return dfs(m,n,k-1,0,0,dp,prsum);
    }
};