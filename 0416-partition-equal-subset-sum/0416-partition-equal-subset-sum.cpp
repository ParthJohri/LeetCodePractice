class Solution {
public:
    bool partition(int sum,int n,vector<int>&nums,vector<vector<int>>&dp){
        if(sum==0) return true;
        if(n<0) return false;
        if(dp[n][sum]!=-1) return dp[n][sum];
        bool isPossible=true,notConsideredIthElement=false,consideredIthElement=false;
        notConsideredIthElement=partition(sum,n-1,nums,dp);
        if(sum-nums[n]>=0)
        consideredIthElement=partition(sum-nums[n],n-1,nums,dp);
        isPossible=notConsideredIthElement|consideredIthElement;
        return dp[n][sum]=isPossible;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        sum/=2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return partition(sum,n-1,nums,dp);
    }
};