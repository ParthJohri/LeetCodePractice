class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans=nums;
        int x=0,y=0;
        for(auto i:ans)
        {
            if(i!=0)
                nums[x++]=i;
            else if(i==0)
                nums[nums.size()-1-y++]=i;
        }
    }
};