class Solution {
public:
    bool isValid(int r,int c,int rows,int cols){
        if(r>=rows or r<0 or c<0 or c>=cols) return false;
        return true;
    }
    int dfs(int r,int c,vector<vector<int>>&dp,vector<vector<int>>&grid){
        if(dp[r][c]!=-1) return dp[r][c];
        int length=0,rows=grid.size(),cols=grid[0].size();
        int nc=upper_bound(grid[r].begin(),grid[r].end(),grid[r][c])-grid[r].begin();
        if(isValid(r,nc,rows,cols) && grid[r][nc]>grid[r][c]){
            length = max(length,1+dfs(r,nc,dp,grid));
        }
        int nr=upper_bound(grid[c].begin(),grid[c].end(),grid[r][c])-grid[c].begin();
        if(isValid(nr,c,rows,cols) && grid[nr][c]>grid[r][c]){
            length = max(length,1+dfs(nr,c,dp,grid));
        }
        if(dp[r][c]<=length) dp[r][c]=length;
        return dp[r][c];
    }
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int rows=mat.size(),cols=mat[0].size();
        int ans=INT_MIN;
        vector<int> row(rows,0),col(cols,0);
        map<int,vector<pair<int,int>>> m;
        set<int,greater<int>> s;
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                m[mat[i][j]].push_back({i,j});
                s.insert(mat[i][j]);
            }
        }
        for(auto element:s){
            for(auto indexPair:m[element]){
                int r=indexPair.first;
                int c=indexPair.second;
                dp[r][c]=max(row[r],col[c])+1;
            }
            for(auto indexPair:m[element]){
                int r=indexPair.first;
                int c=indexPair.second;
                row[r]=max(row[r],dp[r][c]);
                col[c]=max(col[c],dp[r][c]);
            }
        }
        for(auto i:row){
            ans=max(ans,i);
        }
        for(auto i:col){
            ans=max(ans,i);
        }
        return ans;
    }
};