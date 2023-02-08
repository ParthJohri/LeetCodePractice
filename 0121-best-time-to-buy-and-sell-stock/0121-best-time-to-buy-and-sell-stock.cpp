class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        vector<int> su(nums.size());
        su[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            su[i]=max(nums[i],su[i+1]);
        }
        for(int i=0;i<nums.size()-1;i++){
            ans=max(ans,su[i]-nums[i]);
        }
        return ans;
    }
};