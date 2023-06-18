class Solution {
public:
    bool isValid(int r,int c,int rows,int cols){
        if(r>=rows or r<0 or c>=cols or c<0) return false;
        return true;
    }
    long long dfs(int r,int c,vector<vector<int>>&dp,vector<vector<int>>&grid){
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        if(dp[r][c]!=-1) return dp[r][c];
        long long length=0;
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(isValid(nr,nc,grid.size(),grid[0].size()) and grid[nr][nc]>grid[r][c]){
                length = max(length,1+dfs(nr,nc,dp,grid));
            }
        }
        if(dp[r][c]<length) dp[r][c]=length;
        return length;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        long long maxLength=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                maxLength=max(maxLength,1+dfs(i,j,dp,matrix));
            }
        }
        return maxLength;
    }
};