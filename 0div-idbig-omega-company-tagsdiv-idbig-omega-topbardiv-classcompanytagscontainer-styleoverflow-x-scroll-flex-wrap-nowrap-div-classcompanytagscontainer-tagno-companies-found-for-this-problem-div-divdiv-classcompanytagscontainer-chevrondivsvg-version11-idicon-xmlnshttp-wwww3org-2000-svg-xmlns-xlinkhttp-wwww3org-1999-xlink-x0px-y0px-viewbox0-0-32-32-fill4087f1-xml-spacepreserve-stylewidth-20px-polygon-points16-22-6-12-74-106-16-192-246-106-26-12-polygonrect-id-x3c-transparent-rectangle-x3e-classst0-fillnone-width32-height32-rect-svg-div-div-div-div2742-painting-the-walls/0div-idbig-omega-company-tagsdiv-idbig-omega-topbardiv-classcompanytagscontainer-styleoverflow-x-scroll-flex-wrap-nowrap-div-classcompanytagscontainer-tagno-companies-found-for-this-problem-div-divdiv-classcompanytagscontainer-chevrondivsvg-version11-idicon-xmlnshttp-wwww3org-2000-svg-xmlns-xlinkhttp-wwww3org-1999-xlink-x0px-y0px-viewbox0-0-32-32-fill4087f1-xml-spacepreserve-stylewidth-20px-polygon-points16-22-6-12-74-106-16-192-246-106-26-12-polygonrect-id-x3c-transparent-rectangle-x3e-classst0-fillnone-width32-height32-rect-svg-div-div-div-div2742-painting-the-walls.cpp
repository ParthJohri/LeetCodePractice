class Solution
{
    public:
        vector<int> c, t;
    int dp[501][501][2];
    int recur(int i, int flag, int time)
    {
        int n = c.size();
        if (time == c.size()) return 0;
        if (i == c.size()) return 1e9;
        if (dp[i][time][flag] != -1) return dp[i][time][flag];
        int paid = INT_MAX, free = INT_MAX;
        int val = min(n, time + t[i]+1);
        paid = recur(i + 1, 1, val) + c[i];
        free = recur(i + 1, 0, time);
        return dp[i][time][flag] = min(paid, free);
    }
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        c = cost;
        t = time;
        memset(dp, -1, sizeof(dp));

        return recur(0, 0, 0);
    }
};