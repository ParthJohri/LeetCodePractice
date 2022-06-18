class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,count=0,mx=*max_element(nums.begin(),nums.end()),k=2;
        for(auto i:nums) sum+=i;
        if(sum<target) return 0;
        if(mx>=target) return 1;
        if(sum==target) return nums.size();
        for(k=2;k<=nums.size();k++)
        {
            sum=0;
            for(int i=0;i<k;i++)
            {
                sum+=nums[i];
            }
            if(sum>=target) return k;
            for(int i=k;i<nums.size();i++)
            {
                sum+=nums[i]-nums[i-k];
                if(sum>=target) return k;
            }
        }
        return 0;
    }
};