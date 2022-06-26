class Solution {
public:
    void subbacktrack(vector<vector<int>> &v,vector<int> temp,vector<int> &nums,int start)
    {
        v.push_back(temp);
        for(int i=start;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            subbacktrack(v,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        subbacktrack(ans,vector<int>(),nums,0);
        return ans;
    }
};