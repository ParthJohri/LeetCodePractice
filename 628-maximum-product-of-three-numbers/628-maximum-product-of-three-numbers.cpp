class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count=0;
        for(auto i:nums)
           { if(i<0)
                ++count;}
        if(count==nums.size())
            return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        else if(nums[0]>=0)
            return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        else
        {
            if(nums[0]*nums[1]>=nums[nums.size()-1]*nums[nums.size()-2])
                return nums[nums.size()-1]*nums[1]*nums[0];
            else if(nums[0]*nums[1]>=nums[nums.size()-2]*nums[nums.size()-3])
                return nums[0]*nums[1]*nums[nums.size()-1];
        }
        return nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
    }
};