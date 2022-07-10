class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0,rightsum=0;
        for(auto i:nums) rightsum+=i;
        for(int i=0;i<nums.size();i++) {
            rightsum-=nums[i];
            if(leftsum==rightsum) return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};