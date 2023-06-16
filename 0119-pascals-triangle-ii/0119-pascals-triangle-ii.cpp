class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> table;
        table.resize(50);
        for(int i=0;i<rowIndex+1;i++){
            table[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++){
                table[i][j]=table[i-1][j-1]+table[i-1][j];
            }
        }
        return table[rowIndex];
    }
};