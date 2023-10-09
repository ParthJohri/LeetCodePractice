class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size(),total_subsets=1<<n;
        vector<vector<int>> ans(total_subsets);
        for(int i=0;i<total_subsets;i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};