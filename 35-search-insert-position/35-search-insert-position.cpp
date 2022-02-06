class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        while(start<end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
                end=mid;
            else
                start=mid+1;
        }
        if(nums[end]<target)
            end++;
        return end;
    }
};