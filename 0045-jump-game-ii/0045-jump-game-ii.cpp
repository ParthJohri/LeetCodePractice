class Solution {
public:
    long long int recur(int curr, vector<int>& dp, vector<int>&nums){
        if(curr>=nums.size()-1) return 0;
        if(dp[curr]!=INT_MAX) return dp[curr];
        for(int i=1;i<=nums[curr];i++){
            if(dp[curr]>1+recur(i+curr,dp,nums))
            dp[curr]=1+recur(i+curr,dp,nums);
        }
        return dp[curr];
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX);
        int n=nums.size();
        recur(0,dp,nums);
        return dp[0]==INT_MAX?0:dp[0];
    }
};