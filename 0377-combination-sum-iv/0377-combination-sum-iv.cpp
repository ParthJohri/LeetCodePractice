class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return combination(nums,target,dp);
    }
    int combination(vector<int>&nums,int target,vector<int>&dp){
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        dp[target]=0;
        for(auto &i:nums){
            if(i<=target)
            dp[target]+=combination(nums,target-i,dp);
        }
        return dp[target];
    }
};