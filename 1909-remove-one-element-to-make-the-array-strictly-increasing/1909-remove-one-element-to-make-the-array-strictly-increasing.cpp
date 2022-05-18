class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>=nums[i])
            {
                --count;
                if(count<0)
                    return false;
                if(i>1&&nums[i-2]>=nums[i])
                    nums[i]=nums[i-1];
            }
        }
        return true;
    }
};