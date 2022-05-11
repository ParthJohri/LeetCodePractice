class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> v(101,0);
        int ans=0;
        for(auto i:nums)
        {
            ans+=v[i]++;
        }
         return ans;
    }
};