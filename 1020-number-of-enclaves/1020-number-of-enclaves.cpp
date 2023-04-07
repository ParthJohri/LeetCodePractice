class Solution {
private: 
    int ans=0;
public:
    void dfs(int row,int col, vector<vector<int>>&grid){
        if(row<0 or col<0 or row>=grid.size() or col>=grid[0].size() or grid[row][col]==0) return;
        grid[row][col]=0;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        ans++;
        for(int i=0;i<4;i++){
            int r=row+dx[i],c=col+dy[i];
            dfs(r,c,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            dfs(i,0,grid);
            dfs(i,m-1,grid);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,grid);
            dfs(n-1,j,grid);
        }
        ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};