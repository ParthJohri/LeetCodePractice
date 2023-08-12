class Solution
{
    public:
        long long int dp[1001][1001];
        vector<vector < int>> grid, cost;

    long long int recur(int i, int j)
    {
        int n = grid.size(), m = grid[0].size();
        if (i >= n or j >= m) return INT_MAX;
        if (i == n - 1) return grid[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        long long int ans = INT_MAX;
            for (int k = 0; k < m; k++)
            {
                ans = min(ans, recur(i + 1, k) + grid[i][j] + cost[grid[i][j]][k]);
            }

        return dp[i][j] = ans;
    }
    int minPathCost(vector<vector < int>> &grid, vector< vector< int>> &moveCost)
    {
        memset(dp, -1, sizeof(dp));
        this->grid = grid;
        cost = moveCost;
        long long int ans = INT_MAX;
        for(int i = 0;i<grid[0].size();i++){
            ans = min(ans, recur(0,i));
        }
        return ans;
    }
};