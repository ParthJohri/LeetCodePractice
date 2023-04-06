class Solution {
public:
    void dfs(vector<vector<int>>&grid, int r,int c){
        if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or grid[r][c]!=0) return;
        grid[r][c]=1;
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int xx=r+x[i],yy=c+y[i];
            // if(xx>=0 and yy>=0 and xx<grid.size() and yy<grid[0].size() and grid[xx][yy]==0)
            dfs(grid,xx,yy);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            dfs(grid,i,0);
            dfs(grid,i,n-1);
        }
        for(int j=0;j<n;j++){
            dfs(grid,0,j);
            dfs(grid,m-1,j);
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0) {
                    dfs(grid,i,j); 
                    ans++;
                }
            }
        }
        return ans;
    }
};