class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median=nums[nums.size()/2],ans=0;
        for(auto i:nums){
            ans+=abs(i-median);
        }
        return ans;
    }
};