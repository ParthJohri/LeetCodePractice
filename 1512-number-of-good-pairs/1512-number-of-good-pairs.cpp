class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Do this problem after this
        // https://www.codechef.com/START38C/problems/GOODPAIRS
        vector<int> v(101,0);
        int ans=0;
        for(auto i:nums)
        {
            ans+=v[i]++;
        }
         return ans;
    }
};