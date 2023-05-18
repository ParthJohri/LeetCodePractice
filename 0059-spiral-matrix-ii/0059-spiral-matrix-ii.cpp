class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int count=1;
        int rowStart=0,colStart=0,rowEnd=n-1,colEnd=n-1;
        while(rowStart<=rowEnd and colStart<=colEnd){
            for(int i=colStart;i<=colEnd;i++){
                ans[rowStart][i]=count++;
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd;i++){
                ans[i][colEnd]=count++;
            }
            colEnd--;
            for(int i=colEnd;i>=colStart;i--){
                ans[rowEnd][i]=count++;
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowStart;i--){
                ans[i][colStart]=count++;
            }
            colStart++;
        }
        return ans;
    }
};