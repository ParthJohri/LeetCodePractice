class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(auto i:nums){
            auto it=lower_bound(dp.begin(),dp.end(),i);
            if(it==dp.end())
                dp.push_back(i);
            else
                *it=i;
        }
        return dp.size();
    }
};