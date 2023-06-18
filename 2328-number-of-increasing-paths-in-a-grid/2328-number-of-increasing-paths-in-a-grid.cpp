class Solution {
public:
    long long mod=1e9+7;
    bool isValid(int r,int c,int rows,int cols){
        if(r>=rows or r<0 or c<0 or c>=cols) return false;
        return true;
    }
    long long dfs(int r,int c,vector<vector<int>>&dp,vector<vector<int>>&grid){
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        if(dp[r][c]!=-1) return dp[r][c];
        long long count=1;
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(isValid(nr,nc,grid.size(),grid[0].size()) and grid[nr][nc]>grid[r][c]){
                count=(count%mod+dfs(nr,nc,dp,grid)%mod)%mod;
            }
        }
        return dp[r][c]=count;
    }
    int countPaths(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        long long count=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                count=(count%mod+dfs(i,j,dp,grid)%mod)%mod;
            }
        }
        return count%mod;
    }
};