class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long long ans=1,left=0,right=1,n=nums.size(),curr_num=nums[0];
        // [1,3,8,48,10]
        while(right<n){
            while(left<right and (nums[right]&curr_num)!=0){
                curr_num=(~nums[left])&curr_num;
                left++;
            }
            ans=max(ans,right-left+1);
            curr_num^=nums[right];
            right++;
        }
        return ans;
    }
};