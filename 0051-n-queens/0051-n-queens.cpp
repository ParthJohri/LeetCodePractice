class Solution {
public:
    bool check(int row, int col,vector<string>&board){
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
    void Nqueen(int row, int col, vector<string>&board,vector<vector<string>>&ans){
        if(row==board.size()){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<board.size();j++){
            if(check(row,j,board)){
                board[row][j]='Q';
                Nqueen(row+1,col,board,ans);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string temp="";
        // i{} => i=0
        for(int i{};i<n;i++){
            temp+=".";
        }
        vector<string> board(n,temp);
        vector<vector<string>> ans;
        Nqueen(0,0,board,ans);
        return ans;
    }
};