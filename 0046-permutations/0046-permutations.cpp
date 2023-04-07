class Solution {
public:
    void dfs(vector<vector<int>>&v,vector<int>&nums,int index){ 
        if(index>=nums.size()) {
            v.push_back(nums);
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            dfs(v,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> v;
       dfs(v,nums,0);
       // do{
       //     v.push_back(nums);
       // }while(next_permutation(nums.begin(),nums.end()));
       return v;
    }
};