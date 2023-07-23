class Solution {
public:
    int dr[4]={1,0,-1,0};
    int dc[4]={0,1,0,-1};
    bool check(int x,int y,int m,int n){
        return x>=0 and y>=0 and x<m and y<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int mnAns=0,cnt=0,count=0;
        int m=grid.size(),n=grid[0].size();
        int vis[m][n];
        memset(vis,0,sizeof(vis));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            mnAns=max(mnAns,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(check(nr,nc,m,n) and grid[nr][nc]==1 and vis[nr][nc]==0){
                    q.push({{nr,nc},t+1});
                    vis[nr][nc]=2;
                    ++count;
                }
            }
        }
        if(cnt!=count) return -1;
        return mnAns;
    }
};