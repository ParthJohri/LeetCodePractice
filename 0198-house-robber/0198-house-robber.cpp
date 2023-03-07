class Solution {
public:
    int recur(int index,vector<int>&nums,vector<int>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int rob=0,notrob=0;
        rob=nums[index]+recur(index+2,nums,dp);
        notrob=recur(index+1,nums,dp);
        return dp[index]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+10,-1);
        return recur(0,nums,dp);
    }
};