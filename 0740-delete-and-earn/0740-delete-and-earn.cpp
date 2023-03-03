class Solution {
public:
    int recur(vector<int>&nums,int n,map<int,int>&m,vector<int>&dp){
        if(n>=nums.size()) return 0;
        if(dp[n]!=-1) return dp[n];
        int val=m[nums[n]]*nums[n];
        int temp=n;
        while(temp<nums.size() and (nums[n]==nums[temp] or nums[n]+1==nums[temp])){
            temp++;
        }
        int pick=val+recur(nums,temp,m,dp),notpick=recur(nums,n+1,m,dp);
        return dp[n]=max(pick,notpick);
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        map<int,int> m;
        for(auto i:nums) m[i]++;
        vector<int> dp(nums.size()+1,-1);
        int mx=recur(nums,0,m,dp);
        return dp[0];
    }
};