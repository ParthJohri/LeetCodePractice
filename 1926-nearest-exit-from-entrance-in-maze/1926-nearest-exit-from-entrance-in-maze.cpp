class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int dist=1;
        queue<vector<int>> q;
        q.push({entrance[0],entrance[1]});
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int row=maze.size(),col=maze[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        vis[entrance[0]][entrance[1]]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto n=q.front();
                q.pop();
                int x=n[0],y=n[1];
                for(int i=0;i<4;i++)
                {
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 and ny>=0 and nx<maze.size() and ny<maze[0].size() and maze[nx][ny]!='+' and vis[nx][ny]==false) {
                        q.push({nx,ny});
                        vis[nx][ny]=true;
                                            if(nx==0 or ny==0 or nx==row-1 or ny==col-1) {cout<<nx<<" "<<ny<<endl;return dist;}
                    }
                }
            }   
            dist++;
        }
        return -1;
    }
};