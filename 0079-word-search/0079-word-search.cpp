class Solution {
public:
    vector<vector<char>> board;
    string word;
    bool dfs(int i,int j, int x){
        int n=board.size(),m=board[0].size();
        if(x==word.size()) return true;
        if(i>=n or j>=m or i<0 or j<0 or board[i][j]!=word[x]) return false;
        board[i][j]='*';
        bool ans =  dfs(i+1,j,x+1) or dfs(i,j+1,x+1) or dfs(i-1,j,x+1) or dfs(i,j-1,x+1);
        board[i][j]=word[x];
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->board=board;
        this->word=word;
        int n=board.size(),m=board[0].size();
        if(word == "") return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0)) return true;
                }
            }
        }    
        return false;
    }
};