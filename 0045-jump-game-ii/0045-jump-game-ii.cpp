class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<long long int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int forward=min(nums[i]+i,n-1);
            for(int j=i;j<=forward;j++){
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};