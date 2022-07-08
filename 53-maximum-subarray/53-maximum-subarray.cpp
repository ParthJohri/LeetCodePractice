class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum(nums.size());
        int mx=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum[i]+=nums[i];
            if(i>0&&sum[i]<sum[i-1]+sum[i])
            {
                sum[i]+=sum[i-1];
            }
            mx=max(sum[i],mx);
        }
        return mx;
    }
};