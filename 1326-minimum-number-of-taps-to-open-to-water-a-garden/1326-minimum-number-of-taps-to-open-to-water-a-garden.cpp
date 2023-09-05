class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<long long int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            int left_coverage = max(i-ranges[i],0);
            int right_coverage = min(i+ranges[i],n);
            for(int j=left_coverage;j<=right_coverage;j++){
                dp[j]=min(dp[j],dp[left_coverage]+1);
            }
        }
        return dp[n]==INT_MAX?-1:dp[n];
    }
};