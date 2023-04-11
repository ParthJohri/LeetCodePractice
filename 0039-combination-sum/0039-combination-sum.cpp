class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>c,vector<int>&nums,int index,int target){
        if(target<0 or index>=nums.size()) return;
        if(target==0) {
            ans.push_back(c);
            return;
        }
        recur(ans,c,nums,index+1,target);
        c.push_back(nums[index]);
        recur(ans,c,nums,index,target-nums[index]);
        c.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>c;
        recur(ans,c,nums,0,target);
        return ans;
    }
};