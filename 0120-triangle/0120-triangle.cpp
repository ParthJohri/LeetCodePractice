class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(),n=triangle[0].size();
        int ans=INT_MAX;
        vector<vector<int>> dp(m,vector<int>(m,INT_MAX));
        for(int j=0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=min(dp[i+1][j+1],dp[i+1][j])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};