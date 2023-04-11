class Solution {
public:
    void recur(vector<vector<int>>&ans,vector<int>temp,vector<int>&nums,int index,int target){
        if(index>nums.size() or target<0) return;
        if(target==0) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i!=index and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            recur(ans,temp,nums,i+1,target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        recur(ans,temp,candidates,0,target);
        return ans;
    }
};