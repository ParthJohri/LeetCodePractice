class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int m[101]={0};
        vector<int> ans(101,0);
        
        for(auto i: nums)
        {
            m[i]++;
        }
        
        int sum=0;
        
        for(int i=0;i<101;i++)
        {
            if(m[i]!=0)
            ans[i]=sum;;
            sum+=m[i];
        }
       
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=ans[nums[i]];
        }
        return nums;
    }
};