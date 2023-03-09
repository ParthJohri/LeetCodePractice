class Solution {
public:
    void dfs(vector<vector<char>>&b, int row, int col,int n,int m){
        b[row][col]='V';
        int x[4]={1,0,-1,0};
        int y[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            if(row+x[i]>=n or row+x[i]<0 or col+y[i]>=m or col+y[i]<0) continue;
            if(b[row+x[i]][col+y[i]]=='X')
            dfs(b,row+x[i],col+y[i],n,m);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    dfs(board,i,j,n,m);
                    ++count;
                }
            }
        }
        return count;
    }
};