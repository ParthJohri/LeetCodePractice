class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0) return nums[0];
        if(k%2 and nums.size()==1) return -1;
        if(k==1) return nums[1];
        int ans=nums[0],val=-1;
        if(k==2 and nums.size()==k) return nums[0];
        if(k==2) return max(nums[0],nums[2]);
        for(int i=1;i<=k-2 and i<nums.size();i++){
            ans=max(ans,nums[i]);
        }
        if(k<nums.size()) val=nums[k];
        return max(ans,val);
    }
};