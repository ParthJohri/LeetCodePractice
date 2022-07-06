class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool check=false;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<=nums[i+1])
                continue;
            if(check) return false;
            if(i==0 || nums[i+1]>=nums[i-1])
            {
                nums[i]=nums[i+1];      
                check=true;
            }
            else 
            {
                nums[i+1]=nums[i];
                check=true;
            }
        }
        return true;
    }
};