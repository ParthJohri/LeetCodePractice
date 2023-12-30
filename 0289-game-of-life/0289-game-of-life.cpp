class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans=board;
        vector<vector<int>> dir={{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1}};
        int row=board.size(),col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int count=0;
                for(auto d:dir){
                    int nx=i+d[0],ny=j+d[1];
                    if(nx>=0 and ny>=0 and nx<row and ny<col){
                        count+=board[nx][ny]==1?1:0;
                    }
                }
                if(board[i][j]==1 and (count<2 or count>3)) ans[i][j]=0;
                else if(board[i][j]==1 and (count==2 or count==3)) ans[i][j]=1;
                else if(count==3 and board[i][j]==0) ans[i][j]=1;
            }
        }
        board=ans;
    }
};