class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pr(nums.size(),1);
        int suf=1;
        for(int i=1;i<nums.size();i++){
            pr[i]*=pr[i-1]*nums[i-1];
        }
        for(int i=nums.size()-1;i>=0;i--){
            pr[i]*=suf;
            suf*=nums[i];
        }
        return pr;
    }
};