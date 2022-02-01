class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int left=0,right=1,mx=0,mxmx=-1;
        while(right<nums.size())
        {
            if(nums[left]<nums[right])
            {
                mx=nums[right]-nums[left];
                mxmx=max(mx,mxmx);
            }
            else
                left=right;
            right++;
        }
        return mxmx;
    }
};