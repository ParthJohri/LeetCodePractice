class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]<nums[i-1]+nums[i])
            {
                nums[i]+=nums[i-1];
            }
            mx=max(nums[i],mx);
        }
        return mx;
    }
};