class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=*max_element(nums.begin(),nums.end());
        int len=1,mx=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==ans){
                while(i<nums.size()-1 and nums[i]==nums[i+1]){
                    ++len;
                    i++;
                }
                mx=max(mx,len);
                len=1;
            }
        }
        return mx;
    }
};