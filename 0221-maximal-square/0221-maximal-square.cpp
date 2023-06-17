class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        if(rows==0) return 0;
        int mx=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if((i==0 or j==0) and matrix[i][j]=='1') dp[i][j]=1;
                else if(matrix[i][j]=='1'){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
                mx=max(mx,dp[i][j]);
            }
        }
        return mx*mx;
    }
};