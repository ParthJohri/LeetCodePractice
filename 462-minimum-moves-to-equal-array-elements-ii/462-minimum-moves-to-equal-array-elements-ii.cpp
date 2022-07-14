class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int mdpos=nums.size()&1?(nums.size()-1)/2:nums.size()/2;
        int ans=0;
        for(auto i:nums){
            ans+=abs(i-nums[mdpos]);
        }
        return ans;
    }
};