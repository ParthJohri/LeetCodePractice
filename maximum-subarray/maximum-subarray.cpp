class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,mx=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
            {++count;}
        }
        if(count==nums.size())
        { mx=nums[0];
         for(int i=0;i<nums.size();i++)
             mx=max(mx,nums[i]);
         return nums.size()==1?nums[0]:mx;;
        }
        for(int i=0;i<nums.size();i++){
            cs+=nums[i];
            cs=cs>0?cs:0;
            mx=max(mx,cs);
        }
       
    return nums.size()==1?nums[0]:mx;}
};