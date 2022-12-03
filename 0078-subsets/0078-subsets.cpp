class Solution {
public:
    void createSubset(vector<int> &nums,int n,vector<vector<int>>&ans,vector<int>v){
        if(n<0){
            ans.push_back(v);
            return;
        }
        createSubset(nums,n-1,ans,v);
        v.push_back(nums[n]);
        createSubset(nums,n-1,ans,v);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        createSubset(nums,nums.size()-1,ans,v);
        return ans;
    }
};