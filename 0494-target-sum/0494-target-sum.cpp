class Solution {
public:
    int recur(vector<int>&nums,int target,int index,int sum){
        if(index==nums.size()) return sum==target;
        return recur(nums,target,index+1,nums[index]+sum) + recur(nums,target,index+1,-nums[index]+sum);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums,target,0,0);
    }
};