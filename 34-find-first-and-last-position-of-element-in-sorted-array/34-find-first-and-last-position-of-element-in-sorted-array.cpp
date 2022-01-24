class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,last=-1;
        int low=0,high=nums.size()-1,mid=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]>target)
                high=mid-1;
            else if(nums[mid]<target)
                low=mid+1;
            else
            {
                if(mid==0||nums[mid]!=nums[mid-1])
                    {first=mid;break;}
                else
                    high=mid-1;
            }
        }
        low=0,high=nums.size()-1,mid=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(nums[mid]>target)
                high=mid-1;
            else if(nums[mid]<target)
                low=mid+1;
            else
            {
                        if(mid==nums.size()-1||nums[mid]!=nums[mid+1])
                    {last=mid;break;}
                else
                    low=mid+1;
            }
        }
        return {first,last};
    }
};