class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 0 - red, 1 - white, 2 - blue
        // DNF ( Dutch National Flag ) APPROACH
        int low,mid,high;
        low=0;
        mid=0;
        high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};