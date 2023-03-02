class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0,left=0,right=0;
        vector<int> v;
        int x=0,count=0;
        for(right=0;right<nums.size();right++){
           if(nums[right]==0){
               ++count;
               v.push_back(right);
           }
           if(count>k){
               count--;
               left=v[x++]+1;
           }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};