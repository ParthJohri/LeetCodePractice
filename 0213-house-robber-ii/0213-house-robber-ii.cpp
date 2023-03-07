class Solution {
public:
    int recur(int index,vector<int>&nums,vector<int>&dp,int check){
        if(check==1 and index==nums.size()-1) return 0;
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int rob=0,notrob=0;
        rob=nums[index]+recur(index+2,nums,dp,check);
        notrob=recur(index+1,nums,dp,check);
        return dp[index]=max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+10,-1);
        vector<int> dp2(nums.size()+10,-1);
        if(nums.size()==1) return nums[0];
        return max(recur(0,nums,dp,1),recur(1,nums,dp2,0));
    }
};