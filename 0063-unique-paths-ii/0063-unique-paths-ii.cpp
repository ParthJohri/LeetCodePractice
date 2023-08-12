class Solution {
public:
    int dp[101][101];
    vector<vector<int>> grid;
    int recur(int i,int j){
        int n = grid.size(), m = grid[0].size();
        if(i == n-1 and j == m-1 and grid[i][j]!=1) return 1;
        if(i>=n or j>=m or grid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int rightPath = recur(i,j+1), downPath = recur(i+1,j);
        int ans = rightPath+downPath;
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        grid = obstacleGrid;
        memset(dp,-1,sizeof(dp));
        return recur(0,0);
    }
};