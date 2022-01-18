class Solution {
public:
    int binarysearch(vector<int> nums,int target, bool beta)
    {
        int start=0;
        int end=nums.size()-1;
        int mid=0;
        int ini=-1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]==target)
               {ini=mid;
               if(beta)
               {
                   end=mid-1;
               }
                else
                {
                    start=mid+1;
                }
               }
            else if(target>nums[mid])
                start=mid+1;
            else
                end=mid-1;
        }
        return ini;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> pos(2,0);
        pos[0]=binarysearch(nums,target,true);
        pos[1]=binarysearch(nums,target,false);
        return pos;
    }
};