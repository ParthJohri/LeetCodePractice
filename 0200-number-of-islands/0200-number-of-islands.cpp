class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        grid[i][j]='2';
        int m=grid.size(),n=grid[0].size();
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        for(int k=0;k<4;k++){
            if(i+x[k]>=m or j+y[k]>=n or i+x[k]<0 or j+y[k]<0 or grid[i+x[k]][j+y[k]]=='2') continue;
            if(grid[i+x[k]][j+y[k]]=='1')
                dfs(grid,i+x[k],j+y[k]);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};