class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // sort then find the median of the array nums
        // just find the difference and add it in the ans variable
        // sort(nums.begin(),nums.end(),greater<int>());
        // Using Sort TC: O(NLogN)
        // Therefore Use Partial Sort or Nth Element to find the Median in O(N) Time
        auto middle=nums.begin()+nums.size()/2;
        nth_element(nums.begin(),middle,nums.end());
        int mdpos=nums.size()&1?(nums.size()-1)/2:nums.size()/2;
        int ans=0;
        for(auto i:nums){
            ans+=abs(i-nums[mdpos]);
        }
        return ans;
    }
};