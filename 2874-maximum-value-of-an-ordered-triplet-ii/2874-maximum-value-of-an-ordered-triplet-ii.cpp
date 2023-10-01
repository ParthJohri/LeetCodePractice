class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int left=nums[0];
        vector<int> right(nums.size(),nums[nums.size()-1]);
        for(int i=nums.size()-2;i>=0;i--){
            right[i]=max(right[i+1],nums[i]);
        }
        for(int i=0;i<nums.size()-1;i++){
            left=max(left,nums[i]);
            long long val = (left-nums[i])*1ll*right[i+1];
            ans=max(val,ans);
        }
        return ans;
    }
};