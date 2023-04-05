class Solution {
public:
    bool check(int row, int col, vector<string>&board){
        int i=row,j=col;
        while(i>=0){
            if(board[i][col]=='Q') return false;
            i--;
        }
        i=row;
        while(i>=0 and j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(i>=0 and j<board.size()){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void Nqueencount(int row, int col,vector<string>&board,int& ans){
        if(row==board.size()){
            ans++;
            return;
        }
        for(int j=0;j<board.size();j++){
            if(check(row,j,board)){
                board[row][j]='Q';
                Nqueencount(row+1,col,board,ans);
                board[row][j]='.';
            }
        } 
    }
    int totalNQueens(int n) {
        string temp="";
        int ans=0;
        for(int i{};i<n;i++){
            temp+=".";
        }
        vector<string> board(n,temp);
        Nqueencount(0,0,board,ans);
        return ans;
    }
};