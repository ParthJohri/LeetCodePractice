class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&b){
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        if(i<0 or j<0 or i==b.size() or j==b[0].size()) return;
        b[i][j]='P';
        for(int index=0;index<4;index++){
            int xx=i+x[index],yy=j+y[index];
            if(xx<0 or yy<0 or xx>=b.size()-1 or yy>=b[0].size()-1) continue;
            if(b[xx][yy]=='O') {
                dfs(xx,yy,b);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')
            dfs(i,0,board);
            if(board[i][board[0].size()-1]=='O')
            dfs(i,board[0].size()-1,board);
        }
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O')
            dfs(0,i,board);
            if(board[board.size()-1][i]=='O')
            dfs(board.size()-1,i,board);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='P') board[i][j]='O';
                else board[i][j]='X';
            }
        }
    }
};