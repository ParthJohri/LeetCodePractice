class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum=0,mn=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0 && k-->0)
                nums[i]=-nums[i];
            sum+=nums[i];
        }
        if(k%2==0)
                return sum;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
               mn=min(mn,nums[i]);
        }
        
        if(k>0)
            sum-=2*mn;
        return sum;
    }
};