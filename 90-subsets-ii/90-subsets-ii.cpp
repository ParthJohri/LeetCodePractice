class Solution {
public:
    void subset(set<vector<int>>&ans,vector<int> v,vector<int>&nums,int x){
        if(x==nums.size()) return;
        v.push_back(nums[x]);
        ans.insert(v);
        subset(ans,v,nums,x+1);
        v.pop_back();
        ans.insert(v);
        subset(ans,v,nums,x+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        subset(s,vector<int>(),nums,0);
        vector<vector<int>> ans;
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};