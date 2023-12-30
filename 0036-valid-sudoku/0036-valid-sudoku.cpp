class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> row[10],col[10],sq[10];
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char val=board[i][j];
                if(val=='.') continue;
                int s=(i/3)*3+(j/3);
                if(row[i][val]>0 or col[j][val]>0 or sq[s][val]>0) return false;
                row[i][val]++;
                col[j][val]++;
                sq[s][val]++;
            }
        }
        return true;
    }
};