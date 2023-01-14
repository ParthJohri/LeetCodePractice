class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j,int& val){
        grid[i][j]=2;
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        int m=grid.size(),n=grid[0].size();
        for(int k=0;k<4;k++){
            int xx=i+x[k],yy=j+y[k];
            if(xx>=m or yy>=n or xx<0 or yy<0 or grid[xx][yy]==2)
                continue;
            if(grid[xx][yy]==1){
                ++val;
                dfs(grid,xx,yy,val);
            }
        }
        return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0,val=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,val=1);
                ans=max(ans,val);}
            }
        }
        return ans;
    }
};