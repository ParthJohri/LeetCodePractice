class Solution {
public:
    bool check(vector<vector<int>>&grid,int x,int y){
        if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size() or grid[x][y]==1) return 0;
        grid[x][y]=1;
        return 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=INT_MAX;
        queue<pair<int,int>> q;
        q.push({0,0});
        if(grid[0][0]==1) return -1;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                if(x==m-1 and y==n-1) return level+1;
                int xx[8]={1,0,-1,0,1,1,-1,-1};
                int yy[8]={0,1,0,-1,1,-1,1,-1};
                for(int i=0;i<8;i++){
                    int nx=x+xx[i];
                    int ny=y+yy[i];
                    if(check(grid,nx,ny)){
                        q.push({nx,ny});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};