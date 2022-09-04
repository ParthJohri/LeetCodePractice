class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int mx=0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]+nums[i+1]>nums[i+2] and nums[i+1]+nums[i+2]>nums[i] and                               nums[i]+nums[i+2]>nums[i+1])
            mx=max(mx,nums[i]+nums[i+1]+nums[i+2]);
        }
        return mx;
    }
};